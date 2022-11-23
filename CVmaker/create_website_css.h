#ifndef CREATE_WEBSITE_CSS_H_INCLUDED
#define CREATE_WEBSITE_CSS_H_INCLUDED


void createWebsiteCSSFile()
{
    FILE *fp;
    fp = fopen("website_style.css", "w");
    if(fp == NULL)
        printf("Failed to create style.css file.\n");

    fprintf(fp, "%s", "*{"
            "margin: 0;"
            "padding: 0;"
            "box-sizing: border-box;"
            "font-family: 'Montserrat', sans-serif;"
            "}"

            "a{"
            "text-decoration: none;"
            "}"

            "a:hover{"
            "text-decoration: none;"
            "}"

            "ul{"
            "list-style: none;"
            "}"

            ".header{"
            "position: relative;"
            "width: 100%;"
            "height: 100vh;"
            "background-image: url(images/back.png);"
            "background-repeat: no-repeat;"
            "background-size: cover;"
            "}"

            ".header .navbar{"
            "width: 100%;"
            "height: 80px;"
            "display: flex;"
            "align-items: center;"
            "padding-top: 20px;"
            "}"


            ".logo a{"
            "text-decoration: none;"
            "color: #fff;"
            "display: block;"
            "font-size: 30px;"
            "margin-left: 50px;"
            "}"

            ".menu ul {"
            "margin-left: 192px;"
            "}"

            ".menu ul li{"
            "display: inline-block;"
            "margin-right: 35px;"
            "cursor: pointer;"
            "align-items: center;"

            "}"

            ".menu ul li a{"
            "text-decoration: none;"
            "color:#fff;"
            "font-size: 17px;"
            "font-weight: 500;"
            "letter-spacing: 1px;"
            "}"

            ".header .contact-info{"
            "color: #fff;"
            "margin-left: 400px;"
            "}"

            ".header .contact-info ul{"
            "margin-left: 41px;"
            "}"

            ".header .contact-info ul li{"
            "display: inline-block;"
            "}"

            ".header .contact-info ul li a{"
            "color: #fff;"
            "font-size: 15px;"
            "transition: all 0.3s;"
            "}"

            ".header .contact-info ul li a:hover{"
            "color:#c32865;"
            "}"

            ".header .contact-info ul li a.sep{"
            "margin: 0 28px;"
            "opacity: 0.3;"
            "}"


            ".banner{"
            "position: absolute;"
            "top: 35%;"
            "left:"
            "color: #fff;"
            "}"

            ".app-text{"
            "text-align: center;"
            "}"

            ".app-text h3{"
            "margin-top: 35px;"
            "font-size: 40px;"
            "color: #fff;"
            "font-weight: 900;"
            "letter-spacing: 2px;"
            "text-transform: uppercase;"
            "}"

            ".app-text h1{"
            "font-size: 80px;"
            "position: relative;"
            "color: #fff;"
            "margin-top: 30px;"
            "font-weight: 700;"
            "line-height: 1.3;"
            "}"

            ".app-text h1 span{"
            "color: #c32865;"
            "}"

            ".app-text p{"
            "font-size: 19px;"
            "margin: 30px 30px 30px 0;"
            "letter-spacing: 1px;"
            "color: #fff;"
            "text-align: center;"
            "line-height: 1.5;"
            "letter-spacing: 3px;"
            "}"
            ".social-icons{"
            "position: absolute;"
            "right: 50px;"
            "bottom: 2%;"
            "}"


            ".social-icons ul li{"
            "width: 50px;"
            "height: 50px;"
            "display: inline-block;"
            "}"

            ".social-icons ul li a{"
            "display: block;"
            "color: #fff;"
            "text-align: center;"
            "padding: 12px 17px;"
            "font-size: 20px;"
            "font-weight: 700;"
            "border-radius: 10px;"
            "cursor: pointer;"
            "transition: all 0.5s;"
            "}"

            ".social-icons ul li a:hover{"
            "background: #c32865;"
            "color: #fff;"
            "}");

    fclose(fp);
}


#endif // CREATE_WEBSITE_CSS_H_INCLUDED