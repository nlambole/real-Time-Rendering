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

var vao;
var vbo;
var mvpUniform;

var orthographicProjectionMatrix;

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
	"uniform mat4 u_mvp_matrix;"+
	"void main(void)"+
	"{"+
	"gl_Position = u_mvp_matrix * vPosition;"+
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
	"out vec4 FragColor;"+
	"void main(void)"+
	"{"+
	"FragColor = vec4(1.0, 1.0, 1.0, 1.0);"+
	"}";
	
	fragmentShaderObject = gl.createShader(gl.FRAGMENT_SHADER);
	gl.shaderSource(fragmentShaderObject, fragmentShaderSourceCode);
	gl.compileShader(fragmentShaderObject);
	if (gl.getShaderParameter(fragmentShaderObject, gl.COMPILE_STATUS)==false)
	{
			var error=gl.gerShaderInfoLog(fragmentShadeObject);
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
	
	// *** vertices, colors, shader attribs, vbo, vao, initializations ***
	var triangleVertices = new Float32Array([
											0.0, 50.0, 0.0,
											-50.0, -50.0, 0.0,
											50.0, -50.0, 0.0
											]);
											
	vao = gl.createVertexArray();
	gl.bindVertexArray(vao);

	vbo = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, vbo);
	gl.bufferData(gl.ARRAY_BUFFER, triangleVertices, gl.STATIC_DRAW);
	gl.vertexAttribPointer(WebGLMacros.NRL_ATTRIBUTE_VERTEX, 3, //3 is XYZ co-ordinates in our triangleVertices arra
															 gl.FLOAT,
															 false,
															 0,
															 0);
															 
	gl.enableVertexAttribArray(WebGLMacros.NRL_ATTRIBUTE_VERTEX);
	gl.bindBuffer(gl.ARRAY_BUFFER, null);
	gl.bindVertexArray(null);
	
	// set clear color
	gl.clearColor(0.0, 0.0, 1.0, 1.0); ///BlueColor
	
	// initialize projection matrix
	orthographicProjectionMatrix = mat4.create();
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
	
	// Orthographics Projection => left, right, bottom, top, near, far
	if (Canvas.width <= Canvas.height)
	{
		mat4.ortho(orthographicProjectionMatrix, -100.0, 100.0, (-100.0 * (Canvas.height/Canvas.width)), (100.0 * (Canvas.height / Canvas.width)), -100.0, 100.0);
	}
	else
	{
		mat4.ortho(orthographicProjectionMatrix, (-100.0 * (Canvas.width/Canvas.height)), (100.0 * (Canvas.width/Canvas.height)), -100.0, 100.0, -100.0, 100.0);
	}
}

function display()
{
	gl.clear(gl.COLOR_BUFFER_BIT);
	
	gl.useProgram(shaderProgramObject);
	
	var modelViewMatrix = mat4.create();
	var modelViewProjectionMatrix = mat4.create();
	
	mat4.multiply(modelViewProjectionMatrix, orthographicProjectionMatrix, modelViewMatrix);
	gl.uniformMatrix4fv(mvpUniform, false, modelViewProjectionMatrix);
	gl.bindVertexArray(vao);
	gl.drawArrays(gl.TRIANGLES, 0, 3);
	
	gl.useProgram(null);
	
	//animation loop
	requestAnimationFrame(display, Canvas);
}

function uninitialize()
{
	//code
	if (vao)
	{
		gl.deleteVertexArray(vao);
		vao = null;
	}
	
	if (vbo)
	{
		gl.deleteBuffer(vbo);
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

/*
var cancelAnimationFrame = window.cancelAnimationFrame ||
						   window.webkitCancelRequestAnimationFrame || window.webkitCancelAnimationFrame ||
						   window.mozCancelRequestAnimationFrame || window.mozCancelAnmationFrame ||
						   window.oCancelRequestAnimationFrame || window.oCancelAnimationFrame ||
						   window.msCancelRequestAnimationFrame || window.msCancelAnimationFrame;
						   
*/