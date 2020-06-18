try
{
    $cart = getCookie("cart").split(",");
    for (let i = 0; i < $cart.length; i++)
    {
        if (typeof $cart[i] == "string")
            $cart[i] = parseInt($cart[i], 10);
    }
}
catch
{
    $cart = [];
}

function addtocart(id)
{
    if ($cart.indexOf(id) == -1)
    {
        $cart.push(id);
        $("#lot_" + id).find(".add_button").text("Убрать из корзины");
    }
    else
    {
        delete $cart[$cart.indexOf(id)];
        $("#lot_" + id).find(".add_button").text("Добавить в корзину");

        $cart = $cart.filter(function (el)
        {
            return el != undefined;
        });
    }
    if ($cart.length != 0)
    {
        document.cookie="cart=" + $cart;
    }
    else
    {
        deleteCookie("cart");
    }
}

function isincart(id)
{
    if ($cart.indexOf(id) == -1)
    {
        return "Добавить в корзину";
    }
    else
    {
        return "Убрать из корзины";
    }
}

$.ajax({
    url: './js/json/paintings.json',
    success: function($data)
    {
        $object = "<div class=\"lot_list\">";
        $data.forEach($value => {
            $id = $value["id"];
            $path = $value["path"];
            $author = $value["author"];
            $author_path = $value["author_path"]
            $title = $value["title"];
            $desc = $value["desc"];
            $img = $value["img"];
            $start_cost = $value["start_cost"];
            $text = isincart($id);

            $object += "<div class=\"lot\" id=\"lot_" + $id + "\">";
            $object += "<a class=\"lot_link\" href=\"" + $path + "\" title=\"" + $title + "\">" + $title + "</a>";
            $object += "<a class=\"lot_author\" href=\"" + $author_path + "\">" + $author + "</a>";
            $object += "<img class=\"lot_img\" src=\"" + $img + "\" alt=\"" + $title + "\"/>";
            $object += "<span class=\"lot_desc\">" + $desc + "</span>";
            $object += "<span class=\"lot_cost\">Стартовая стоимость: $" + $start_cost + "</span>";
            $object += "<a class=\"add_button\" onclick=\"addtocart(" + $id + ")\">"+ $text + "</a>";
            $object += "</div>";
        });
        $object += "</div>";
        $("main").append($object);
        
        $("main").append("<div class=\"pages\"><a>1</a><a href=\"#\">2</a><a href=\"#\">3</a><a href=\"#\">4</a><a href=\"#\">5</a></div>");
    }
});