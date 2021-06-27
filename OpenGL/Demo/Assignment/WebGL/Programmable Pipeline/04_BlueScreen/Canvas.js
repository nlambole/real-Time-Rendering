var gl = null;
var Canvas = null;
var canvas_original_width;
var canvas_original_height;
var bFullscreen = false;
var requestAnimationFrame = window.requestAnimationFrame || 
							window.webkitRequestAnimationFrame ||
							window.mozRequestAnmationFrame ||
							window.oRequestAnimationFrame ||
							window.msRequestAnimationFrame;

function main()
{
  Canvas = document.getElementById("NRL") //document is in-Built Variable

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
    if (!gl)
    {
      console.log("WebGL2 is recieve successfully !!!");
    }
    else
    {
      console.log("WebGL2 is recieve FAILED !!!");
    }
	
	//ViewPort Initialization
	gl.viewportWidth = Canvas.width;
	gl.viewportHeight = Canvas.height;
	
	gl.clearColor(0.0, 0.0, 1.0, 1.0,); ///BlueColor
	
	resize(); // wram-up resize
    display(); //warm-up display due to absent repend
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
}

function display()
{
	gl.clear(gl.COLOR_BUFFER_BIT);
	
	requestAnimationFrame(display, Canvas);
}


/*
var cancelAnimationFrame = window.cancelAnimationFrame ||
						   window.webkitCancelRequestAnimationFrame || window.webkitCancelAnimationFrame ||
						   window.mozCancelRequestAnimationFrame || window.mozCancelAnmationFrame ||
						   window.oCancelRequestAnimationFrame || window.oCancelAnimationFrame ||
						   window.msCancelRequestAnimationFrame || window.msCancelAnimationFrame;
						   
*/