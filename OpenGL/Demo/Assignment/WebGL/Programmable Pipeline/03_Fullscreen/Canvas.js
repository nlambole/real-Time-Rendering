var context = null;
var Canvas = null;

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

    //Retrive the height and width of canvas for sake of covinieence
    console.log("Canvas Width = "+Canvas.width+" Canvas Hieght = "+Canvas.height+"\n");

    //getContext From the Canvas
    context = Canvas.getContext("2d");

    if (!context)
    {
      console.log("Obtaining context Failed");
    }
    else
    {
      console.log("Obtaining context Succeded...");
    }

    //Paint backround by Black colour
    context.fillStyle = "black";
    context.fillRect(0, 0, Canvas.width, Canvas.height);

    drawText("Hello World !!!");

    //Events
    window.addEventListener("keydown", keyDown, false); //window is in-Built Variable
    window.addEventListener("click", mouseDown, false);
}

function drawText(text)
{
  //Centre the text
  context.textAlign = "center"; // Horizontal center
  context.textBaseline = "middle"; //Verticle center

  //font
  context.font = "48px sans-serif";

  //Colour the text
  context.fillStyle = "white";
  context.fillText(text, Canvas.width/2, Canvas.height/2)
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
                            }
}

function keyDown(event)
{
    switch (event.keyCode)
    {
      case 70:
      toggleFullscreen();
      drawText("Hello World !!!");  //There is no repend in web based prog. language
        break;
      default:

    }
}

function mouseDown()
{

}
