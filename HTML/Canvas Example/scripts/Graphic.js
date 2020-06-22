window.addEventListener("load", null);

let html = document.documentElement;
let body = document.body;
let overflow = html.style.overflow;
html.style.overflow = "hidden";
body.style.display = "none";

let element = document.createElement('canvas');
element.className = "lcanvas";
element.style.position = "absolute";

element.height = document.documentElement.clientHeight;
element.width  = document.documentElement.clientWidth;
canvas = element.getContext("2d");
clear();

function graphic() {
    
    function draw()
    {
        let x1, y1, x2, y2;
        document.addEventListener("mousedown", click);
    }

    function click(e)
    {
        x1 = e.pageX;
        y1 = e.pageY;
        document.addEventListener("mouseup", release);
    }

    function release(f)
    {
        document.removeEventListener("mouseup", release);
        document.addEventListener("mousedown", click);
        x2 = f.pageX;
        y2 = f.pageY;
        console.log(x1 + " : " + y1 + "; " + x2 + " : " + y2);

        if (type == 1)
        {
            canvas.beginPath();
            canvas.fillRect(x1, y1, x2 - x1, y2 - y1);
        }

        else if (type == 2)
        {
            canvas.beginPath();
            canvas.arc(x1, y1, Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2)), 2*Math.PI, false);
            canvas.fill();
        }
        else if (type == 3)
        {
            canvas.beginPath();
            canvas.moveTo(x1, y1);
            canvas.lineTo(Math.abs(x1 + x2) / 2, y2);
            canvas.lineTo(x2, y1);
            canvas.fill();
        }
        requestAnimationFrame(draw);
    }

    html.prepend(element);
    draw();
};

function clear()
{
    canvas.fillStyle = "#FFF";
    canvas.fillRect (0, 0, element.width, element.height);
    canvas.fillStyle = "#000";
}

let type = 1;

graphic();

console.log("Чтобы сменить тип фигуры, введите \"type = <1/2/3>\" для прямоугольника, круга и треугольника, соответственно.\nЧтобы очистить экран, введите \"clear()\"");