// GlobaL Variables
var gl = null;
var Canvas = null;
var canvas_original_width;
var canvas_original_height;
var bFullscreen = false;


const WebGLMacros = {
NRL_ATTRIBUTE_VERTEX:0,
NRL_ATTRIBUTE_COLOR:1,
NRL_ATTRIBUTE_NORMAL:2,
NRL_ATTRIBUTE_TEXTURE:3
};

var vertexShaderObject;
var fragmentShaderObject;
var shaderProgramObject;

//For (Front Textures) AMC/HullGroup
var vao_Rectangle_Front;
var vbo_Rectangle_Front;
var vbo_Position_Rectangle_Front;
var vbo_Texture_Rectangle_Front;

//For (Back Textures) Credits
var vao_Rectangle_Back;
var vbo_Rectangle_Back;
var vbo_Position_Rectangle_Back;
var vbo_Texture_Rectangle_Back;

var mvpUniform;
var textureSamplerUniform;
var perspectiveProjectionMatrix;

//Textures
var texture_AstroMedicomp;
var texture_HullGroup;
var texture_Credits;

//Transformation
let y = -7.0;

// To start animation : To have requestAnimationFrame() to be called "cross-browser" camptible
var requestAnimationFrame = window.requestAnimationFrame ||
							window.webkitRequestAnimationFrame ||
							window.mozRequestAnimationFrame ||
							window.oRequestAnimationFrame ||
							window.msRequestAnimationFrame;
							
// To Stop animation : To have cancelAnimationFrame() to be Called "cross-browser" campatible
var cancelAnimationFrame = window.cancelAnimationFrame ||
						   window.webkitCancelRequestAnimationFrame || window.webkitCancelAnimationFrame ||
						   window.mozCancelRequestAnimationFrame || window.mozCancelAnimationFree ||
						   window.oCancelRequestAnimationFrame || window.oCancelAnimationFrame ||
						   window.msCancelRequestAnimationFrame || window.msCancelAnimationFrame;

function main()
{
	Canvas = document.getElementById("NRL"); //document is in-Built Variable

    if (!Canvas)
    {
      console.log("Obtaining Canvas Failed");
    }
    else
    {
      console.log("Obtaining Canvas Succeded...");
    }

    canvas_original_width = Canvas.width;
    canvas_original_height = Canvas.height;

    //Events
    window.addEventListener("keydown", keyDown, false); //window is in-Built Variable
    window.addEventListener("click", mouseDown, false);
    window.addEventListener("resize", resize, false); //bubbling

    initialize();
	resize(); // wram-up resize
    display(); //warm-up display due to absent repend

}


function toggleFullscreen()
{
  var fullscreen_element = document.fullscreenElement ||         // Browser Agnostick
                           document.webkitFullscreenElement ||  //Safari
                           document.mozFullScreenElement ||    //Mozila Firefox
                           document.msFullscreenElement ||    //Internet Explorer / Microsoft Edge
                           null;                             //Other Browsers

                            if (fullscreen_element == null) //for Other Browsers
                            {
                                if (Canvas.requestFullscreen) //Function Pointer
                                {
                                    Canvas.requestFullscreen();
                                }
                                else if (Canvas.webkitRequestFullscreen)
                                {
                                    Canvas.webkitRequestFullscreen();
                                }
                                else if (Canvas.mozRequestFullScreen)
                                {
                                    Canvas.mozRequestFullScreen();
                                }
                                else if (Canvas.msRequestFullscreen)
                                {
                                    Canvas.msRequestFullscreen();
                                }
                                bFullscreen = true;
                            }
                            else
                            {
                                if (document.exitFullscreen)
                                {
                                  document.exitFullscreen();
                                }
                                else if (document.webkitExitFullscreen)
                                {
                                  document.webkitExitFullscreen();
                                }
                                else if (document.mozCancelFullScreen)
                                {
                                  document.mozCancelFullScreen();
                                }
                                else if(document.msExitFullscreen)
                                {
                                  document.msExitFullscreen();
                                }
                                bFullscreen = false;
                            }
}

function keyDown(event)
{
    switch (event.keyCode)
    {
      case 70:
      toggleFullscreen();

        break;
      default:

    }
}

function mouseDown()
{

}

function initialize()
{
	//getContext From the Canvas
    gl = Canvas.getContext("webgl2");
    if (gl == null)
    {
		console.log("WebGL2 is recieve FAILED !!!");
    }
    else
    {
       console.log("WebGL2 is recieve successfully !!!");
    }
	
	//ViewPort Initialization
	gl.viewportWidth = Canvas.width;
	gl.viewportHeight = Canvas.height;
	
	//Vertex Shader
	var vertexShaderSourceCode = 
	"#version 300 es"+
	"\n"+
	"in vec4 vPosition;"+
	"in vec2 vTexCord;"+
	"out vec2 out_TexCord;"+
	"uniform mat4 u_mvp_matrix;"+
	"void main(void)"+
	"{"+
	"gl_Position = u_mvp_matrix * vPosition;"+
	"out_TexCord = vTexCord;"+
	"}";
	
	vertexShaderObject = gl.createShader(gl.VERTEX_SHADER);
	gl.shaderSource(vertexShaderObject, vertexShaderSourceCode);
	gl.compileShader(vertexShaderObject);
	
	if (gl.getShaderParameter(vertexShaderObject, gl.COMPILE_STATUS)==false)
	{
		var error = gl.getShaderInfoLog(vertexShaderObject);
		if(error.length > 0)
		{
			alert(error);
			uninitialize();
		}
	}
	
	// Fragment Shader
	var fragmentShaderSourceCode = 
	"#version 300 es"+
	"\n"+
	"precision highp float;"+
	"in vec2 out_TexCord;"+
	"uniform sampler2D u_Texture_Sampler;"+
	"out vec4 FragColor;"+
	"void main(void)"+
	"{"+
	"	vec4 result = texture(u_Texture_Sampler, out_TexCord);"+
	"	if (result.a > 1.0)"+
	"	{"+
	"		discard;"+
	"	}"+
	"FragColor = result;"+
	"}";
	
	fragmentShaderObject = gl.createShader(gl.FRAGMENT_SHADER);
	gl.shaderSource(fragmentShaderObject, fragmentShaderSourceCode);
	gl.compileShader(fragmentShaderObject);
	if (gl.getShaderParameter(fragmentShaderObject, gl.COMPILE_STATUS)==false)
	{
			var error=gl.getShaderInfoLog(fragmentShaderObject);
			if (error.length > 0)
			{
				alert(error);
				uninitialize();
			}
	}
	
	// shader program
	shaderProgramObject = gl.createProgram();
	gl.attachShader(shaderProgramObject, vertexShaderObject);
	gl.attachShader(shaderProgramObject, fragmentShaderObject);
	
	// pre-link binding of shader program object with vertex shader attributes
	gl.bindAttribLocation(shaderProgramObject, WebGLMacros.NRL_ATTRIBUTE_VERTEX, "vPosition");
	gl.bindAttribLocation(shaderProgramObject, WebGLMacros.NRL_ATTRIBUTE_TEXTURE, "vTexCord");
	
	//linking
	gl.linkProgram(shaderProgramObject);
	if(!gl.getProgramParameter(shaderProgramObject, gl.LINK_STATUS))
	{
		var error = gl.getProgramInfoLog(shaderProgramObject);
		if (error.length > 0)
		{
			alert(error);
			uninitialize();
		}
	}
	
	//get MVP Uniform location 
	mvpUniform = gl.getUniformLocation(shaderProgramObject, "u_mvp_matrix");
	textureSamplerUniform = gl.getUniformLocation(shaderProgramObject, "u_Texture_Sampler");
	
	
	// ***********************Rectangle Front Textures (AstromediComp/HullGroup)**************************
	var rectangleVertices_Front = new Float32Array([
											1.7, 1.0, 0.0,
											-1.7, 1.0, 0.0,
											-1.7, -1.0, 0.0,
											1.7, -1.0, 0.0
											
											]);
											
	var rectangleTexCords_Fronts = new Float32Array([
											1.0, 1.0,
											0.0, 1.0,
											0.0, 0.0,
											1.0, 0.0
											]);
		
	//vPosition_Rectangle
	vao_Rectangle_Front = gl.createVertexArray();
	gl.bindVertexArray(vao_Rectangle_Front);

	vbo_Position_Rectangle_Front = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, vbo_Position_Rectangle_Front);
	gl.bufferData(gl.ARRAY_BUFFER, rectangleVertices_Front, gl.STATIC_DRAW);
	gl.vertexAttribPointer(WebGLMacros.NRL_ATTRIBUTE_VERTEX, 3, //3 is XYZ co-ordinates in our triangleVertices arra
															 gl.FLOAT,
															 false,
															 0,
															 0);
															 
	gl.enableVertexAttribArray(WebGLMacros.NRL_ATTRIBUTE_VERTEX);
	gl.bindBuffer(gl.ARRAY_BUFFER, null);
	
	//vColor_Rectangle
	vbo_Texture_Rectangle_Front = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, vbo_Texture_Rectangle_Front);
	gl.bufferData(gl.ARRAY_BUFFER, rectangleTexCords_Fronts, gl.STATIC_DRAW);
	gl.vertexAttribPointer(WebGLMacros.NRL_ATTRIBUTE_TEXTURE, 2, 
															 gl.FLOAT,
															 false,
															 0,
															 0);
															 
	gl.enableVertexAttribArray(WebGLMacros.NRL_ATTRIBUTE_TEXTURE);
	gl.bindBuffer(gl.ARRAY_BUFFER, null);
	gl.bindVertexArray(null);

	// ***********************Rectangle For Credit Texture**************************
	var rectangleVertices_Back = new Float32Array([
													2.0, 5.0, 0.0,
													-2.0, 5.0, 0.0,
													-2.0, -5.0, 0.0,
													2.0, -5.0, 0.0
													]);
		
var rectangleTexCords_Back = new Float32Array([
													1.0, 1.0,
													0.0, 1.0,
													0.0, 0.0,
													1.0, 0.0
													]);

//vPosition_Rectangle
vao_Rectangle_Back = gl.createVertexArray();
gl.bindVertexArray(vao_Rectangle_Back);

vbo_Position_Rectangle_Back = gl.createBuffer();
gl.bindBuffer(gl.ARRAY_BUFFER, vbo_Position_Rectangle_Back);
gl.bufferData(gl.ARRAY_BUFFER, rectangleVertices_Back, gl.STATIC_DRAW);
gl.vertexAttribPointer(WebGLMacros.NRL_ATTRIBUTE_VERTEX, 3, //3 is XYZ co-ordinates in our triangleVertices arra
						 gl.FLOAT,
						 false,
						 0,
						 0);
						 
gl.enableVertexAttribArray(WebGLMacros.NRL_ATTRIBUTE_VERTEX);
gl.bindBuffer(gl.ARRAY_BUFFER, null);

//vColor_Rectangle
vbo_Texture_Rectangle_Back = gl.createBuffer();
gl.bindBuffer(gl.ARRAY_BUFFER, vbo_Texture_Rectangle_Back);
gl.bufferData(gl.ARRAY_BUFFER, rectangleTexCords_Back, gl.STATIC_DRAW);
gl.vertexAttribPointer(WebGLMacros.NRL_ATTRIBUTE_TEXTURE, 2, 
						 gl.FLOAT,
						 false,
						 0,
						 0);
						 
gl.enableVertexAttribArray(WebGLMacros.NRL_ATTRIBUTE_TEXTURE);
gl.bindBuffer(gl.ARRAY_BUFFER, null);
gl.bindVertexArray(null);
	
	//LoadTexture
	//************************AstroMediComp**************
	texture_AstroMedicomp = gl.createTexture();
	texture_AstroMedicomp.image = new Image();
	texture_AstroMedicomp.image.src = "AstroMediComp.png";
	texture_AstroMedicomp.image.onload = function ()
	{
		gl.bindTexture(gl.TEXTURE_2D, texture_AstroMedicomp);
		gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
		gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
        gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
		gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, texture_AstroMedicomp.image);
		gl.bindTexture(gl.TEXTURE_2D, null);
	};

	//************************HullGroup**************
	texture_HullGroup = gl.createTexture();
	texture_HullGroup.image = new Image();
	texture_HullGroup.image.src = "HullGroup.png";
	texture_HullGroup.image.onload = function ()
	{
		gl.bindTexture(gl.TEXTURE_2D, texture_HullGroup);
		gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
		gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
        gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
		gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, texture_HullGroup.image);
		gl.bindTexture(gl.TEXTURE_2D, null);
	};

	//************************Credit**************
	texture_Credits = gl.createTexture();
	texture_Credits.image = new Image();
	texture_Credits.image.src = "Credit.png";
	texture_Credits.image.onload = function ()
	{
		gl.bindTexture(gl.TEXTURE_2D, texture_Credits);
		gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
		gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
        gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
		gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, texture_Credits.image);
		gl.bindTexture(gl.TEXTURE_2D, null);
	};
	
	//AlphaBlending
	gl.enable(gl.BLEND);
	gl.blendFunc(gl.SRC_ALPHA, gl.ONE_MINUS_SRC_ALPHA);
	
	// set clear color
	gl.clearColor(0.0, 0.0, 0.0, 1.0); 
	
	//Depth Function
	gl.clearDepth(1.0);
	gl.enable(gl.DEPTH_TEST);
	gl.depthFunc(gl.LEQUAL);
	gl.enable(gl.CULL_FACE);

	// initialize projection matrix
	perspectiveProjectionMatrix = mat4.create();
}


function resize()
{
	if (bFullscreen == true)
	{
		Canvas.width = window.innerWidth;
		Canvas.height = window.innerHeight;
	}
	else
	{
		 Canvas.width = canvas_original_width;
		 Canvas.height = canvas_original_height;
	}
	
	gl.viewport(0.0, 0.0, Canvas.width, Canvas.height);
	
	mat4.perspective(perspectiveProjectionMatrix, 45.0, parseFloat(Canvas.width)/parseFloat(Canvas.height), 0.1, 100.0);
	
}

function display()
{
	gl.clear(gl.COLOR_BUFFER_BIT);
	gl.useProgram(shaderProgramObject);
	
	/*// **************Rect***************************************
	var modelViewMatrix = mat4.create();
	var modelViewProjectionMatrix = mat4.create();
	
	mat4.translate(modelViewMatrix, modelViewMatrix, [0.0, 0.0 , -2.0]);
	mat4.multiply(modelViewProjectionMatrix, perspectiveProjectionMatrix, modelViewMatrix);
	
	gl.uniformMatrix4fv(mvpUniform, false, modelViewProjectionMatrix);
	
	//Texture
	gl.activeTexture(gl.TEXTURE0);
	gl.bindTexture(gl.TEXTURE_2D, texture_AstroMedicomp);
	gl.uniform1i(textureSamplerUniform, 0); // 
	
	gl.bindVertexArray(vao_Rectangle_Front);
	gl.drawArrays(gl.TRIANGLE_FAN, 0, 4);
	gl.bindVertexArray(null);*/

	// **************Rect***************************************
	var modelViewMatrix = mat4.create();
	var modelViewProjectionMatrix = mat4.create();
	
	mat4.translate(modelViewMatrix, modelViewMatrix, [0.0, y, -4.0]);
	mat4.multiply(modelViewProjectionMatrix, perspectiveProjectionMatrix, modelViewMatrix);
	
	gl.uniformMatrix4fv(mvpUniform, false, modelViewProjectionMatrix);
	
	//Texture
	gl.activeTexture(gl.TEXTURE0);
	gl.bindTexture(gl.TEXTURE_2D, texture_Credits);
	gl.uniform1i(textureSamplerUniform, 0); // 
	
	gl.bindVertexArray(vao_Rectangle_Back);
	gl.drawArrays(gl.TRIANGLE_FAN, 0, 4);
	gl.bindVertexArray(null);
	
	
	gl.useProgram(null);
	
	Update();
	
	//animation loop
	requestAnimationFrame(display, Canvas);
}

function degTwoRad(degrees)
{
	
	return degrees * (Math.PI/180.0);
}

function Update()
{
	y = y + 0.005;
	if(y > 5)
	{
		y = 7.0;
	}

}

function uninitialize()
{
	//code
	if (vao_Rectangle_Front)
	{
		gl.deleteVertexArray(vao_Rectangle_Front);
		vao_Rectangle_Front = null;
		
	}
	
	if (vbo_Rectangle_Front)
	{
		gl.deleteVertexArray(vbo_Rectangle_Front);
		vbo_Rectangle_Front = null;
		
	} 
	
	if (vbo_Position_Rectangle_Front)
	{
		gl.deleteVertexArray(vbo_Position_Rectangle_Front);
		vbo_Position_Rectangle_Front = null;
	}
	
	if (vbo_Texture_Rectangle_Front)
	{
		gl.deleteBuffer(vbo_Texture_Rectangle_Front);
		vbo_Texture_Rectangle_Front = null;
	}

	if (vao_Rectangle_Back)
	{
		gl.deleteVertexArray(vao_Rectangle_Back);
		vao_Rectangle_Back = null;
		
	}
	
	if (vbo_Rectangle_Back)
	{
		gl.deleteVertexArray(vbo_Rectangle_Back);
		vbo_Rectangle_Back = null;
		
	} 
	
	if (vbo_Position_Rectangle_Back)
	{
		gl.deleteVertexArray(vbo_Position_Rectangle_Back);
		vbo_Position_Rectangle_Back = null;
	}
	
	if (vbo_Texture_Rectangle_Back)
	{
		gl.deleteBuffer(vbo_Texture_Rectangle_Back);
		vbo_Texture_Rectangle_Back = null;
	}
	
	
	if (shaderProgramObject)
	{
		if (fragmentShaderObject)
		{
			gl.detachShader(shaderProgramObject, fragmentShaderObject);
			gl.deleteShader(fragmentShaderObject);
			fragmentShaderObject = null;
		}
		
		if (vertexShaderObject)
		{
			gl.detachShader(shaderProgramObject, vertexShaderObject);
			gl.detachShader(vertexShaderObject);
			vertexShaderObject = null;
		}
		
		gl.deleteProgram(shaderProgramObject);
		shaderProgramObject = null;
	}
}
