$( document ).ready(function()
{
    try
    {
        $cart = getCookie("cart").split(",");
        for (let i = 0; i < $cart.length - 1; i++)
        {
            if (typeof $cart[i] == "string")
                $cart[i] = parseInt($cart[i], 10);
        }
    }
    catch
    {
        $cart = [];
    }

}); 