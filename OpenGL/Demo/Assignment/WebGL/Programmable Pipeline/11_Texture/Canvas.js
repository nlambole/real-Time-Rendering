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

var vao_Pyramid;
var vbo_Pyramid;
var vbo_Position_Pyramid;
var vbo_Texture_Pyramid;

var mvpUniform;
var textureSamplerUniform;

var perspectiveProjectionMatrix;

var pyramid_Texture;

//Rotation
var Angle_Pyramid = 0.0;

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
	"FragColor = texture(u_Texture_Sampler, out_TexCord);"+
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
	
	
	// ***********************Triangle**************************
	var pyramidVertices = new Float32Array([
											0.0, 1.0, 0.0, //Front
											-1.0, -1.0, 1.0,
											1.0, -1.0, 1.0,

											0.0, 1.0, 0.0, // right
											1.0, -1.0, 1.0,
											1.0, -1.0, -1.0,

											0.0, 1.0, 0.0, // Back
											1.0, -1.0, -1.0,
											-1.0, -1.0, -1.0,

											0.0, 1.0, 0.0, // left
											-1.0, -1.0, -1.0,
											-1.0, -1.0, 1.0
											]);
											
	var pyramidTexCords = new Float32Array([
											0.5, 1.0,
											0.0, 0.0,
											1.0, 0.0,

											0.5, 1.0,
											0.0, 0.0,
											1.0, 0.0,

											0.5, 1.0,
											1.0, 0.0,
											0.0, 0.0,

											0.5, 1.0,
											0.0, 0.0,
											1.0, 0.0
											]);
		
	//vPosition_Triangle
	vao_Pyramid = gl.createVertexArray();
	gl.bindVertexArray(vao_Pyramid);

	vbo_Position_Pyramid = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, vbo_Position_Pyramid);
	gl.bufferData(gl.ARRAY_BUFFER, pyramidVertices, gl.STATIC_DRAW);
	gl.vertexAttribPointer(WebGLMacros.NRL_ATTRIBUTE_VERTEX, 3, //3 is XYZ co-ordinates in our triangleVertices arra
															 gl.FLOAT,
															 false,
															 0,
															 0);
															 
	gl.enableVertexAttribArray(WebGLMacros.NRL_ATTRIBUTE_VERTEX);
	gl.bindBuffer(gl.ARRAY_BUFFER, null);
	
	//vColor_Triangle
	vbo_Texture_Pyramid = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, vbo_Texture_Pyramid);
	gl.bufferData(gl.ARRAY_BUFFER, pyramidTexCords, gl.STATIC_DRAW);
	gl.vertexAttribPointer(WebGLMacros.NRL_ATTRIBUTE_TEXTURE, 2, 
															 gl.FLOAT,
															 false,
															 0,
															 0);
															 
	gl.enableVertexAttribArray(WebGLMacros.NRL_ATTRIBUTE_TEXTURE);
	gl.bindBuffer(gl.ARRAY_BUFFER, null);
	gl.bindVertexArray(null);
	
	
	//Texture
	pyramid_Texture = gl.createTexture();
	pyramid_Texture.image = new Image();
	pyramid_Texture.image.src = "stone.png";
	pyramid_Texture.image.onload = function ()
	{
		gl.bindTexture(gl.TEXTURE_2D, pyramid_Texture);
		gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
		gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
        gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
		gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, pyramid_Texture.image);
		gl.bindTexture(gl.TEXTURE_2D, null);
	};
	
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
	
	// **************Triangle***************************************
	var modelViewMatrix = mat4.create();
	var rotationMatrix = mat4.create();
	var scaleMatrix = mat4.create();
	var modelViewProjectionMatrix = mat4.create();
	
	mat4.translate(modelViewMatrix, modelViewMatrix, [0.0, 0.0, -4.0]);
	
	mat4.rotateY(rotationMatrix, rotationMatrix, degTwoRad(Angle_Pyramid));
	mat4.multiply(modelViewMatrix, modelViewMatrix, rotationMatrix);
	mat4.multiply(modelViewProjectionMatrix, perspectiveProjectionMatrix, modelViewMatrix);
	
	gl.uniformMatrix4fv(mvpUniform, false, modelViewProjectionMatrix);
	
	//Texture
	gl.activeTexture(gl.TEXTURE0);
	gl.bindTexture(gl.TEXTURE_2D, pyramid_Texture);
	gl.uniform1i(textureSamplerUniform, 0); // 
	
	gl.bindVertexArray(vao_Pyramid);
	gl.drawArrays(gl.TRIANGLES, 0, 12);
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
	Angle_Pyramid = Angle_Pyramid + 1.0;
	if (Angle_Pyramid >= 360)
	{
		Angle_Pyramid = 0.0;
	}

}

function uninitialize()
{
	//code
	if (vao_Pyramid)
	{
		gl.deleteVertexArray(vao_Pyramid);
		vao_Pyramid = null;
		
	}
	
	if (vbo_Pyramid)
	{
		gl.deleteVertexArray(vbo_Pyramid);
		vbo_Pyramid = null;
		
	} 
	
	if (vbo_Position_Pyramid)
	{
		gl.deleteVertexArray(vbo_Position_Pyramid);
		vbo_Position_Pyramid = null;
	}
	
	if (vbo_Texture_Pyramid)
	{
		gl.deleteBuffer(vbo_Texture_Pyramid);
		vbo_Texture_Pyramid = null;
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
