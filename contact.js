
function contact_us(){
    if(document.getElementById("name_contact").value.trim() == ""){
        $(document).ready(function(){
            document.getElementById("denialtext").innerHTML = "❌ No name included!"
            $("#confirmation").slideUp();
            $("#denial").slideDown();
          });

    }
    else if(document.getElementById("email_contact").value.trim() == ""){
        $(document).ready(function(){
            document.getElementById("denialtext").innerHTML = "❌ No email included!"
            $("#confirmation").slideUp();
            $("#denial").slideDown();
          });

    }
    else if(document.getElementById("email_contact").value.includes("@") & document.getElementById("email_contact").value.includes(".")){
        
        var data = $("form[name=algoForm]").serialize();
        if(document.getElementById("message_area").value.trim() == ""){
    
            $(document).ready(function(){
                document.getElementById("denialtext").innerHTML = "❌ No message included!"
                $("#confirmation").slideUp();
                $("#denial").slideDown();
              });
            
        }
        else{
            $.ajax({
                url: "https://script.google.com/macros/s/AKfycbyb2E3kgUvkuK7d4OGIsQ8KkrD4ZUTsW3i0ytYjsg/exec",
                type: "POST",
                data: data,
                success: function(response){
                    if(response != null){
                        $(document).ready(function(){
                            document.getElementById("confirmationtext").innerHTML = "✔ Message Sent!"
                            $("#denial").slideUp();
                            $("#waiting").slideUp();
                            $("#confirmation").slideDown();
                            document.getElementById("name_contact").value = "";
                            document.getElementById("email_contact").value = "";
                            document.getElementById("message_area").value = "";
                          });
    
                    }
                    else{
                        $(document).ready(function(){
                            document.getElementById("denialtext").innerHTML = "❌ Your message was not sent. Please try again."
                            $("#denial").slideDown();
                          });
                        
                    }
                }
            }) 
            $(document).ready(function(){
                $("#denial").slideUp();
                $("#confirmation").slideUp();
                $("#waiting").slideDown();
              });  
            }
    }
    else{
        $(document).ready(function(){
            document.getElementById("denialtext").innerHTML = "❌ Not a valid email!"
            $("#confirmation").slideUp();
            $("#denial").slideDown();
          });
    }
}

function closebutton(name){
    $(document).ready(function(){
        $(name).slideUp();
      });

  }