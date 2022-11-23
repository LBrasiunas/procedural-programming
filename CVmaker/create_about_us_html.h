#ifndef CREATE_ABOUT_US_HTML_H_INCLUDED
#define CREATE_ABOUT_US_HTML_H_INCLUDED

// A function responsible for creating the About Us .html file
void createAboutUsHTML()
{
    FILE *fp;
    fp = fopen("about.html", "w");
    if(fp == NULL)
        printf("Failed to create About Us file.\n");

        fprintf(fp, "%s", "<!DOCTYPE html>"
        "<html>"
        "<head>"
            "<title>CV Maker About Us</title>"
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
                        "<li><a href=\"website.html\">Home</a></li>"
                        "<li><a href=\"#\">About Us</a></li>"
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
            "<div class=\"app-text\">"
                    "<h3>Who are we?</h3>"
                    "<p>"
                    "Software engineering students from Vilnius University."
                    "</p>"
                    "<h3>Our contacts</h3>"
                    "<p>"
                        "Gustas Juškevičius (gustas.juskevicius@mif.stud.vu.lt) <br>"
                        "Lukas Brasiūnas (lukas.brasiunas@mif.stud.vu.lt) <br>"
                        "Ugnius Motiejūnas (ugnius.motiejunas@mif.stud.vu.lt)"
                    "</p>"
            "</div>"
        "</div>"
        "</body>"
        "</html>");

    fclose(fp);
}

#endif // CREATE_ABOUT_US_HTML_H_INCLUDED
