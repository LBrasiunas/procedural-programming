#ifndef CREATE_CSS_H_INCLUDED
#define CREATE_CSS_H_INCLUDED

// A function responsible for creating the .css file
void createCSSFile()
{
    FILE *fp;
    fp = fopen("style.css", "w");
    if(fp == NULL)
        printf("Failed to create style.css file.\n");

    fprintf(fp, "%s", "html {"
        "box-sizing: border-box;"
    "}"
    "*, *:before, *:after {"
    "box-sizing: inherit;"
    "}"

    "body {"
        "font-family: 'Source Sans Pro', sans-serif;"
        "line-height: 1.5;"
        "background: #F2F2F2;"
        "color: #323232;"
    "}"

    "img {"
        "max-width: 100%;"
    "}"

    ".icon {"
        "fill: currentColor;"
        "display: inline-block;"
        "font-size: inherit;"
        "height: 1em;"
        "overflow: visible;"
    "}"

    "a {"
        "color: #323232;"
        "text-decoration: none;"
    "}"

    "a:hover {"
    "text-decoration: underline;"
    "}"

    ".container {"
        "max-width: 960px;"
        "margin: 40px auto;"
        "padding: 32px;"
        "background: white;"
        "box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);"
    "}"

    "section {"
        "display: grid;"
        "grid-template-columns: 1fr 4fr;"
        "grid-gap: 20px;"
        "padding: 24px 0;"
        "border-bottom: 1px solid lightgrey;"
    "}"

    "section:last-child {"
        "border-bottom: none;"
    "}"

    ".section-title {"
        "font-weight: bold;"
        "font-size: 18px;"
    "}"

/***********************************
* =Main Info
***********************************/

    "img.avatar {"
        "width: 130px;"
    "}"

    ".my-name {"
        "font-size: 48px;"
        "line-height: 1;"
    "}"

    ".my-title {"
        "font-size: 24px;"
        "font-weight: 300;"
        "color: #236FB2;"
    "}"

    ".links {"
        "display: flex;"
        "margin: 10px 0 20px 0;"
    "}"

    ".link-item {"
        "display: flex;"
        "align-items: center;"
        "flex: 1;"
    "}"

    ".link-item svg {"
        "margin-right: 6px;"
    "}"

/***********************************
* =Experience
***********************************/

    ".job {"
        "padding-bottom: 24px;"
        "margin-bottom: 24px;"
        "border-bottom: 1px solid lightgrey;"
    "}"

    ".job:last-child {"
        "border-bottom: none;"
    "}"

    ".job-title-container {"
        "display: flex;"
        "justify-content: space-between;"
        "margin-bottom: 20px;"
        "font-size: 18px;"
    "}"

    ".job-company {"
        "font-weight: bold;"
        "line-height: 1.2;"
    "}");

    fclose(fp);
}

#endif // CREATE_CSS_H_INCLUDED
