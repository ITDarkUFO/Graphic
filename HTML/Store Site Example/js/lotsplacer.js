$.ajax({
    url: './js/json/paintings.json',
    success: function($data)
    {
        $object = "<div class=\"lot_list\">";
        $data.forEach($value => {
            $object += "<div class=\"lot\">";
            $path = $value["path"];
            $title = $value["title"];
            $desc = $value["desc"];
            $img = $value["img"];
            $start_cost = $value["start_cost"];
            $object += "<a href=\"" + $path + "\" title=\"" + $title + "\">" + $title + "</a>";
            $object += "<img src=\"" + $img + "\" alt=\"" + $title + "\"/>";
            $object += "<span>Стартовая стоимость: " + $start_cost + "</span>";
            $object += "</div>";
        });
        $object += "</div>";
        $("main").append($object);
        console.log($data); // Выведет содержимое файла в консоль
    }
});