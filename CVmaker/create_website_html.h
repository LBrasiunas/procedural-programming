#ifndef CREATE_WEBSITE_HTML_H_INCLUDED
#define CREATE_WEBSITE_HTML_H_INCLUDED

void createWebsiteHTML()
{
    FILE *fp;
    fp = fopen("website.html", "w");
    if(fp == NULL)
        printf("Failed to create website file\n");

    fprintf(fp, "%s", "<!DOCTYPE html>"
"<html>"
"<head>"
	"<title>CV Maker Homepage</title>"
	"<meta charset=\"UTF-8\">"
	"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
	"<link rel=\"stylesheet\" type=\"text/css\" href=\"website_style.css\">"
    "<link href=\"https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css\" rel=\"stylesheet\">"
    "<link href=\"https://fonts.googleapis.com/css2?family=Montserrat:wght@300;400;500;600;700;800;900&display=swap\" rel=\"stylesheet\">"
"</head>"
"<body>"
"<div class=\"header\">"
     "<div class=\"navbar\">"
         "<div class=\"menu\">"
             "<ul>"
                 "<li><a href="">Home</a></li>"
                 "<li><a href=\"about.html\">About Us</a></li>"
                 "<li><a href=\"CV.html\">Resume</a></li>"
                 "<li><a href=\"https://www.youtube.com/watch?v=dQw4w9WgXcQ\">Services</a></li>"
             "</ul>"
         "</div>"
         "<div class=\"contact-info\">"
            "<ul>"
                "<li><a class=\"phone-no\"> +370 5 272 4444 </a></li>"
                "<li><a class=\"sep\"> / </a></li>"
                "<li><a class=\"email\"> info@picagroup.lt </a></li>"
            "</ul>"

        "</div>"
     "</div>"

     "<div class=\"banner\">"
         "<div class=\"app-text\">"
             "<h1><span>Welcome, </span>this is the CV maker homepage</h1>"
          "</div>"
        "</div>"
     "</div>"
     "<div class=\"social-icons\">"
          "<ul>"
            "<li><a href=\"https://www.youtube.com/watch?v=zYqLtB2LYb0\"><i class=\"fa fa-facebook\"></i></a></li>"
            "<li><a href=\"https://www.youtube.com/watch?v=l1heD4T8Yco\"><i class=\"fa fa-twitter\"></i></a></li>"
            "<li><a href=\"https://www.youtube.com/watch?v=JUe0GaScPdY\"><i class=\"fa fa-linkedin\"></i></a></li>"
            "<li><a href=\"https://www.youtube.com/watch?v=zcrwHlSPubQ\"><i class=\"fa fa-instagram\"></i></a></li>"
            "<li><a href=\"https://www.youtube.com/watch?v=xHfwekKLHi8\"><i class=\"fa fa-youtube\"></i></a></li>"
            "<li><a href=\"https://www.youtube.com/watch?v=VQHDzDb_zjw\"><i class=\"fa fa-pinterest\"></i></a></li>"
          "</ul>"
      "</div>"
  "</div>"
"</body>"
"</html>");

fclose(fp);
}

#endif // CREATE_WEBSITE_HTML_H_INCLUDED
