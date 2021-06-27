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
NRL_ATTRIBUTE_TEXTURE0:3
};

var vertexShaderObject;
var fragmentShaderObject;
var shaderProgramObject;

var vao_Triangle;
var vbo_Triangle;
var vbo_Position_Triangle;
var vbo_Color_Triangle;

var vao_Square;
var vbo_Square;
var vbo_Position_Square;
var vbo_Color_Square;

var mvpUniform;

var vbo_Color;

var perspectiveProjectionMatrix;

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
	"in vec4 vColor;"+
	"out vec4 out_Color;"+
	"uniform mat4 u_mvp_matrix;"+
	"void main(void)"+
	"{"+
	"gl_Position = u_mvp_matrix * vPosition;"+
	"out_Color = vColor;"+
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
	"in vec4 out_Color;"+
	"out vec4 FragColor;"+
	"void main(void)"+
	"{"+
	"FragColor = out_Color;"+
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
	gl.bindAttribLocation(shaderProgramObject, WebGLMacros.NRL_ATTRIBUTE_COLOR, "vColor");
	
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
	
	
	// ***********************Triangle**************************
	var triangleVertices = new Float32Array([
											0.0, 1.0, 0.0,
											-1.0, -1.0, 0.0,
											1.0, -1.0, 0.0
											]);
											
	var triangleColor = new Float32Array([
											1.0, 0.0, 0.0,
											0.0, 1.0, 0.0,
											0.0, 0.0, 1.0
											]);
		
	//vPosition_Triangle
	vao_Triangle = gl.createVertexArray();
	gl.bindVertexArray(vao_Triangle);

	vbo_Position_Triangle = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, vbo_Position_Triangle);
	gl.bufferData(gl.ARRAY_BUFFER, triangleVertices, gl.STATIC_DRAW);
	gl.vertexAttribPointer(WebGLMacros.NRL_ATTRIBUTE_VERTEX, 3, //3 is XYZ co-ordinates in our triangleVertices arra
															 gl.FLOAT,
															 false,
															 0,
															 0);
															 
	gl.enableVertexAttribArray(WebGLMacros.NRL_ATTRIBUTE_VERTEX);
	gl.bindBuffer(gl.ARRAY_BUFFER, null);
	
	//vColor_Triangle
	vbo_Color_Triangle = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, vbo_Color_Triangle);
	gl.bufferData(gl.ARRAY_BUFFER, triangleColor, gl.STATIC_DRAW);
	gl.vertexAttribPointer(WebGLMacros.NRL_ATTRIBUTE_COLOR, 3, //3 is XYZ co-ordinates in our triangleVertices arra
															 gl.FLOAT,
															 false,
															 0,
															 0);
															 
	gl.enableVertexAttribArray(WebGLMacros.NRL_ATTRIBUTE_COLOR);
	gl.bindBuffer(gl.ARRAY_BUFFER, null);
	gl.bindVertexArray(null);
	
	// ******************Square***********************************
	var squareVertices = new Float32Array([
											-1.0, 1.0, 0.0,
											-1.0, -1.0, 0.0,
											1.0, -1.0, 0.0,
											1.0, 1.0, 0.0
											]);
	
	//vPosition_Square
	vao_Square = gl.createVertexArray();
	gl.bindVertexArray(vao_Square);

	vbo_Position_Square = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, vbo_Position_Square);
	gl.bufferData(gl.ARRAY_BUFFER, squareVertices, gl.STATIC_DRAW);
	gl.vertexAttribPointer(WebGLMacros.NRL_ATTRIBUTE_VERTEX, 3, //3 is XYZ co-ordinates in our triangleVertices arra
															 gl.FLOAT,
															 false,
															 0,
															 0);
															 
	gl.enableVertexAttribArray(WebGLMacros.NRL_ATTRIBUTE_VERTEX);
	gl.bindBuffer(gl.ARRAY_BUFFER, null);
	gl.bindVertexArray(null);
	
	//vColor_Square
	gl.vertexAttrib3f(WebGLMacros.NRL_ATTRIBUTE_COLOR, 0.0, 0.0, 1.0);
	gl.bindVertexArray(null);3
	
	
	// set clear color
	gl.clearColor(0.0, 0.0, 0.0, 1.0); 
	

	
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
	var modelViewProjectionMatrix = mat4.create();
	
	mat4.translate(modelViewMatrix, modelViewMatrix, [-1.5, 0.0, -3.0]);
	mat4.multiply(modelViewProjectionMatrix, perspectiveProjectionMatrix, modelViewMatrix);
	
	gl.uniformMatrix4fv(mvpUniform, false, modelViewProjectionMatrix);
	gl.bindVertexArray(vao_Triangle);
	gl.drawArrays(gl.TRIANGLES, 0, 3);
	gl.bindVertexArray(null);
	
	// **************Square******************************************
	modelViewMatrix = mat4.create();
	modelViewProjectionMatrix = mat4.create();
	
	mat4.translate(modelViewMatrix, modelViewMatrix, [1.5, 0.0, -3.0]);
	mat4.multiply(modelViewProjectionMatrix, perspectiveProjectionMatrix, modelViewMatrix);
	
	gl.uniformMatrix4fv(mvpUniform, false, modelViewProjectionMatrix);
	gl.bindVertexArray(vao_Square);
	gl.drawArrays(gl.TRIANGLE_FAN, 0, 4);
	gl.bindVertexArray(null);
	
	gl.useProgram(null);
	
	//animation loop
	requestAnimationFrame(display, Canvas);
}

function uninitialize()
{
	//code
	if (vao_Triangle)
	{
		gl.deleteVertexArray(vao_Triangle);
		vao_Triangle = null;
	}
	
	if (vao_Square)
	{
		gl.deleteVertexArray(vao_Square);
		vao_Square = null;
	}
	
	if (vbo_Color)
	{
		gl.deleteBuffer(vbo_Color);
		vbo_Color = null;
	}
	
	if (vbo_Color_Triangle)
	{
		gl.deleteBuffer(vbo_Color_Triangle);
		vbo = null;
	}
	
	if (vbo_Color)
	{
		gl.deleteBuffer(vbo_Color);
		vbo = null;
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
