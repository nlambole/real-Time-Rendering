function main()
{
    var Canvas = document.getElementById("NRL")

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
    var context = Canvas.getContext("2d");

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

    //Centre the text
    context.textAlign = "center"; // Horizontal center
    context.textBaseline = "middle"; //Verticle center

    //font
    context.font = "48px sans-serif";

    //Declare the string to be displayed
    var str = "Hello World";

    //Colour the text
    context.fillStyle = "white";
    context.fillText(str, Canvas.width/2, Canvas.height/2)
}
