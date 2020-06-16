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
            $object += "<a href=\"" + $path + "\" title=\"" + $title + "\"></a>";
            $object += "</div>";
        });
        $object += "</div>";
        $("main").append($object);
        console.log($data); // Выведет содержимое файла в консоль
    }
});