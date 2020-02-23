from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print("Start :", tag)
        self.print_attrs(attrs)
    def handle_endtag(self, tag):
        print("End   :", tag)
    def handle_startendtag(self, tag, attrs):
        print("Empty :", tag)
        self.print_attrs(attrs)
    
    def print_attrs(self, attrs):
        for elem in attrs:
            print("-> {:} > {:}".format(elem[0], elem[1]))

if __name__ == "__main__":
    parser = MyHTMLParser()
    for _ in range(int(input())):
        parser.feed(input())