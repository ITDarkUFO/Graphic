$.ajax({
    url: './js/json/paintings.json',
    success: function(data)
    {
        $object = "<div class=\"lot\">";
        data.forEach(element => {
            $title = element["title"];
            $path = element["path"];
            $object += "<a href=\"$path\" title=\"$title\"></a>";
            $object += "</div>";
        });
       console.log(data); // Выведет содержимое файла в консоль
    }
});