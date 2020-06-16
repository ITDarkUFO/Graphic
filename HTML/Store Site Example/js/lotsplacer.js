$.ajax({
    url: './js/json/paintings.json',
    success: function(data) {
       console.log(data); // Выведет содержимое файла в консоль
    }
});

// if (window.XMLHttpRequest)
// {
//     xmlhttp = new XMLHttpRequest();
// }
// else
// {// code for IE6, IE5
//     xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
// }
// xmlhttp.open("GET","./js/json/paintings.json", false);
// xmlhttp.send();
// xmlDoc=xmlhttp.responseText;


//     // $json = file_get_contents("./json/paintings.json");
//     // $data = json_decode(json, true);
//     // alert(1);
//     // $object = "<div class=\"lot\">";
//     // foreach($data as $value)) {
        
//     //     $title = $value["title"];
//     //     $path = $value["path"];
//     //     $object .= "<a href=\"$path\" title=\"$title\"></a>
//     // }
//     //$object .= "</div>"
// });