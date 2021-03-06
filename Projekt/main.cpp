#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unistd.h>

class Entity {
    int id;
    std::string titles;
    std::string genres;
    int year;
    int pages;
    int id_authors;
    std::string name;
    std::string lastname;
    int book_id;
    int client_id;
    std::string borrowed;


public:
    Entity() : id(-1), titles("0"), genres({}), year(-1), pages(-1), id_authors(-1), name("0"),
              lastname("0"), book_id(-1), client_id(-1), borrowed("0") {};

    Entity(int id, std::string name, std::string lastname): id(id), name(name), lastname(lastname){};

    Entity(int id, int book_id, int client_id, std::string borrowed): id(id), book_id(book_id), client_id(client_id), borrowed(borrowed){};

    Entity (int id, std::string titles, std::string genres, int year, int pages, int id_authors):
        id(id),
        titles(titles),
        genres(genres),
        year(year),
        pages(pages),
        id_authors(id_authors){};

    Entity getEntity() {
        if (id != -1) {
            if (name != "0") {
                if (lastname != "0") {
                    Entity e(id, name, lastname);
                    std::cout << "Entity author/client" << std::endl;
                    return e;
                }
            }
            else {
                if (book_id != -1) {
                    if (client_id != -1) {
                        if(borrowed != "0") {
                            Entity e(id, book_id, client_id, borrowed);
                            std::cout << "Entity order" << std::endl;
                            return e;
                        }
                    }
                }
                else {
                    if(titles != "0") {
                        if (genres.size() != 0) {
                            if (year != -1) {
                                if (pages != -1) {
                                    if (id_authors != -1) {
                                        Entity e(id, titles, genres, year, pages, id_authors);
                                        std::cout << "Entity book" << std::endl;
                                        return e;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    void setId(int id) {
        this->id = id;
    }

    void setTitles(const std::string &titles) {
        this->titles = titles;
    }

    void setGenres(const std::string &genres) {
        Entity::genres = genres;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setPages(int pages) {
        this->pages = pages;
    }

    void setIdAuthors(int idAuthors) {
        this->id_authors = idAuthors;
    }

    void setName(const std::string &name) {
        this->name = name;
    }

    void setLastname(const std::string &lastname) {
        this->lastname = lastname;
    }

    void setBookId(int bookId) {
        this->book_id = bookId;
    }

    void setClientId(int clientId) {
        this->client_id = clientId;
    }

    void setBorrowed(const std::string &borrowed) {
        Entity::borrowed = borrowed;
    }

    int getId() const {
        return id;
    }

    const std::string &getTitles() const {
        return titles;
    }

    const std::string &getGenres() const {
        return genres;
    }

    int getYear() const {
        return year;
    }

    int getPages() const {
        return pages;
    }

    int getIdAuthors() const {
        return id_authors;
    }

    const std::string &getName() const {
        return name;
    }

    const std::string &getLastname() const {
        return lastname;
    }

    int getBookId() const {
        return book_id;
    }

    int getClientId() const {
        return client_id;
    }

    const std::string &getBorrowed() const {
        return borrowed;
    }

};

std::map<std::string, std::vector<std::string>> headers;
std::map<std::string, std::vector<Entity>> data;
std::map<std::string, int> config;
std::vector<Entity> _data_;

void initializeHeaders() {
    std::vector<std::string> clients = {"id", "name", "lastname"};
    std::vector<std::string> books = {"id", "titles", "genres", "year", "pages", "id authors"};
    std::vector<std::string> authors = {"id", "name", "lastname"};
    std::vector<std::string> orders = {"id", "id books", "id clients",  "lend"};

    headers["books"] = books;
    headers["authors"] = authors;
    headers["clients"] = clients;
    headers["orders"] = orders;

}

void initializeData() {
    std::vector<Entity> clients = {};
    std::vector<Entity> books = {};
    std::vector<Entity> authors = {};
    std::vector<Entity> orders = {};


    data["books"] = books;
    data["authors"] = authors;
    data["clients"] = clients;
    data["orders"] = orders;
}

void initializeConfig() {
    config["books"] = 0;
    config["authors"] = 0;
    config["clients"] = 0;
    config["orders"] = 0;

}

class Tables {

    public:
    static int getColumnIndex(std::string table, std::string headerName) {
        std::cout << "#searching for column index " << headerName << " in table " << table << "..." << std::endl;
        int temp = -1;
        for (int i = 0; i < headers[table].size(); i++) {
            if (headers[table][i] == headerName) {
                temp = i;
            }
        }
        return temp;
    }

    static Entity getById(std::string table, int id) {
        std::cout << "#searching for id " << id << " in table " << table << "..." << std::endl;
        for(Entity item : data[table]) {
            if (item.getId() == id) {
                return item.getEntity();
            }
        }
    }

    static void initializeDB() {

        bool flag = false;
        for(std::map<std::string, std::vector<Entity>>::iterator iter = data.begin(); iter != data.end(); ++iter) {
            std::string table = iter->first;
            std::string filename;
            filename.append(table);
            filename.append(".txt");
            std::ifstream file;
            file.open(filename);
            if (!file) {
                flag = true;
                std::cout << "File " << table << " not found" << std::endl;
            }
            file.close();
        }
        if(flag) {
            std::cout << "There was no existing database" << std::endl;
            createTables();
            std::cout << "~  database was created ~" << std::endl;
        }
        else {
            std::cout << "database exists!" << std::endl;
            readTables();
        }

    }

    static void createTables() {
        for(std::map<std::string, std::vector<Entity>>::iterator iter = data.begin(); iter != data.end(); ++iter) {
            std::string table = iter->first;
            std::string filename;
            filename.append(table);
            filename.append(".txt");
            std::ofstream file;
            file.open(filename);
            if(!file) {
                std::cerr << "file creation error " << table;
            }
            file.close();

            std::cout << "~ table created " << table << "  ~" << std::endl;
        }
    }

    static void writeTables() {
        for(std::map<std::string, std::vector<Entity>>::iterator iter = data.begin(); iter != data.end(); ++iter) {
            std::vector<Entity> item = iter -> second;
            std::string table= iter->first;
            std::string filename;
            filename.append(table);
            filename.append(".txt");
            std::ofstream file;
            file.open(filename); // std::ios::app)
            for(Entity e: item) {
                std::string output;

                if (table == "books") {
                    output.append(std::to_string(e.getId()));
                    output.append(",");
                    output.append(e.getTitles());
                    output.append(",");
                    output.append(e.getGenres());
                    output.append(",");
                    output.append(std::to_string(e.getYear()));
                    output.append(",");
                    output.append(std::to_string(e.getPages()));
                    output.append(",");
                    output.append(std::to_string(e.getIdAuthors()));
                    output.append(",");
                    output.append("\n");
                }

                else if (table == "orders") {
                    output.append(std::to_string(e.getId()));
                    output.append(",");
                    output.append(std::to_string(e.getBookId()));
                    output.append(",");
                    output.append(std::to_string(e.getClientId()));
                    output.append(",");
                    output.append((e.getBorrowed()));
                    output.append(",");
                    output.append("\n");
                }

                else if (table == "clients" || table == "authors") {
                    output.append(std::to_string(e.getId()));
                    output.append(",");
                    output.append(e.getName());
                    output.append(",");
                    output.append(e.getLastname());
                    output.append(",");
                    output.append("\n");
                }
            if(!file) {
                std::cerr << "file opening error " << table;
            }

            file << output;
            }
        file.close();
        }
    }

    static void readTables() {
        for(std::map<std::string, std::vector<Entity>>::iterator iter = data.begin(); iter != data.end(); ++iter) {

            // std::vector<Entity> item = iter->second;
            std::string table = iter->first;
            std::cout << "-read table " << table << std::endl;
            std::string filename;
            filename.append(table);
            filename.append(".txt");
            std::ifstream file;
            file.open(filename);

            if (!file) {
                std::cerr << "File opening error" << table ;
            }

            else {

                file.close();
                if (table == "books") {

                    file.open(filename);
                    std::string input;
                    while (std::getline(file, input)) { // np. 1,Bolek i Lolek, bajka, ...

                        Entity e;
                        std::string value;
                        ////file >> input;
                        if (input.size() > 0) {
                            int i = input.find(",");
                            value = input.substr(0, i);
                            e.setId(std::stoi(value));

                            input = input.substr(i + 1);
                            i = input.find(",");
                            value = input.substr(0, i);
                            e.setTitles(value);

                            input = input.substr(i + 1);
                            i = input.find(",");
                            value = input.substr(0, i);
                            e.setGenres(value);

                            input = input.substr(i + 1);
                            i = input.find(",");
                            value = input.substr(0, i);
                            e.setYear(std::stoi(value));

                            input = input.substr(i + 1);
                            i = input.find(",");
                            value = input.substr(0, i);
                            e.setPages(std::stoi(value));

                            input = input.substr(i + 1);
                            i = input.find(",");
                            value = input.substr(0, i);
                            e.setIdAuthors(std::stoi(value));
                            data[table].push_back(e.getEntity());
                        }
                        else {
                            break;
                        }

                    }
                    file.close();

                } else if (table == "orders") {

                    file.open(filename);
                    std::string input;
                    while (std::getline(file, input)) {
                        Entity e;
                        std::string value;
                        ////file >> input;
                        if (input.size() > 0) {
                            int i = input.find(",");
                            value = input.substr(0, i);
                            e.setId(std::stoi(value));

                            input = input.substr(i + 1);
                            i = input.find(",");
                            value = input.substr(0, i);
                            e.setBookId(std::stoi(value));

                            input = input.substr(i + 1);
                            i = input.find(",");
                            value = input.substr(0, i);
                            e.setClientId(std::stoi(value));

                            input = input.substr(i + 1);
                            i = input.find(",");
                            value = input.substr(0, i);
                            e.setBorrowed(value);

                            data[table].push_back(e.getEntity());
                        }
                        else {
                            break;
                        }

                    }
                    file.close();
                } else if (table == "clients" || table == "authors") {

                    file.open(filename);
                    std::string input;
                    while (std::getline(file, input)) {
                        std::string value;
                        Entity e;
                        ////file >> input;
                        if (input.size() > 0) {
                            ////std::cout << input << std::endl;
                            int i = input.find(",");
                            value = input.substr(0, i);

                            e.setId(std::stoi(value));

                            ////std::cout << value << std::endl;

                            input = input.substr(i + 1);
                            i = input.find(",");
                            value = input.substr(0, i);
                            e.setName(value);

                            ////std::cout << value << std::endl;

                            input = input.substr(i + 1);
                            i = input.find(",");
                            value = input.substr(0, i);
                            e.setLastname(value);

                            ////std::cout << value << std::endl;

                            data[table].push_back(e.getEntity());
                            ////std::cout << "++++++++++++" << std::endl;
                        }
                        else {
                            std::cout << "Tables are empty" << std::endl;
                            break;
                        }
                    }
                    file.close();
                }
            }
        }
        std::cout << std::endl;
    }
};

class System {

    public:
    static void boot() {
        std::cout << "LIBRARY MANAGER IS BOOTING..." << std::endl;
        //TODO: sleep

        initializeConfig();
        initializeData();
        initializeHeaders();

        configLoading();
        Tables::initializeDB();
    }

    static int autoincrement(std::string title) {
        config[title]++;
        return config[title];
    }

    static int decrement(std::string title) {
        config[title]--;
        return config[title];
    }

    static void configLoading() {

        std::ifstream file;
        file.open("config.txt");
        if (file) { //// Config istnieje
            file.close();
            for (std::map<std::string, int>::iterator iter = config.begin(); iter != config.end(); ++iter) {
                std::string item = iter->first;
                int line = 0;

                if(item == "books") {
                    line = 0;
                }
                else if(item == "authors") {
                    line = 1;
                }
                else if(item == "clients") {
                    line  = 2;
                }
                else if(item == "orders") {
                    line = 3;
                }
                file.open("config.txt");
                int i = 0;
                while(true) {
                    std::string input;
                    file >> input;
                    if(i == line) {
                        config[item] = std::stoi(input);
                        break;
                    }
                    i++;
                }
                file.close();
            }
            std::cout << "config read successfully" << std::endl;
            file.close();
        }
        else {
            std::cout << "ERROR: config couldn't be read" << std::endl;
            updateConfig();
        }

    }

    static void updateConfig() {

        std::ofstream file;
        file.open("config.txt");
        for (std::map<std::string, int>::iterator iter = config.begin(); iter != config.end(); ++iter) {
            std::string item = iter->first;
            int value = iter->second;
            file << std::to_string(value) << "\n";
        }
        file.close();

    }

    static void quitting() {
        while(true) {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "     DO YOU WANT TO SAVE CHANGES? (y/n)" << std::endl;
            char order;
            std::cin >> order;
            std::cout << std::endl;
            if (order == 'y') {
                std::cout << "~ config was updated ~";
                updateConfig();
                Tables::writeTables();
                break;
            }
            else if (order == 'n') {
                std::cout << "changes were abandon";
                break;
            }
        }
        std::exit(0);
    }
};

class Interface {

    public:
    static void printHeader(std::string title){
        std::cout  << std::endl;
        std::cout << "  ########################" << std::endl;
        std::cout << std::endl;
        std::cout << "    ~~~ Library database ~~~" << std::endl;
        std::cout << "    "+title << std::endl;
        std::cout << std::endl;
    }

    static std::string printInterface(std::string title, std::vector<std::string> options) {
        printHeader(title);
        std::cout << "     OPTIONS:" << std::endl;
        std::cout << std::endl;

        for (int i = 0; i < options.size(); i++) {
            std::cout << "     " << options[i] << std::endl;
        }

        std::cout << std::endl;
        std::cout << "  ########################" << std::endl;
        std::cout << std::endl;
        std::string order;
        std::cout << "     ~[provide command]~>";
        std::getline(std::cin, order);
        ////std::cout << "order = " << order << std::endl;
        std::cout << std::endl;
        return order;
    }

    static void unknownCommandPrompt() {
        std::cout << "!!! Unrecognised command !!!";
        //tODO: sleep
    }

    static void printTableFromData(std::string title, std::vector<std::string> header,  bool pauseEnded=true) {
        std::cout << "  ########################";
        std::cout << std::endl;
        std::cout << "     " << title;
        std::cout << std::endl;
        for (int i = 0; i < header.size(); i++) {
            std::cout << "     " << header[i] << "  |  " ; //TODO: te pierwsze spacje chyba po za petle
        }
        std::cout << std::endl;
        //for (std::vector<std::string> item: data) {
        for(Entity item : _data_) {
            // std::vector <std::string> temp;
            //for (std::string subitem: item) {
                if (title == "books") {
                    std::cout << "     " << item.getId() << "  |  "
                              << "     " << item.getTitles() << "  |  "
                              << "     " << item.getGenres()<< "  |  "
                              << "     " << item.getYear() << "  |  "
                              << "     " << item.getPages() << "  |  "
                              << "     " << item.getIdAuthors() << "  |  " << std::endl;
                }
                else if (title == "authors" || title == "clients") {
                    std ::cout << "     " << item.getId() << "  |  "
                               << "     " << item.getName() << "  |  "
                               << "     " << item.getLastname() << "  |  " << std:: endl;
                }
                else if (title == "orders") {
                    std::cout << "     " << item.getId() << "  |  "
                              << "     " << item.getBookId() << "  |  "
                              << "     " << item.getClientId() << "  |  "
                              << "     " << item.getBorrowed() << "  |  " << std::endl;
                }
        }
        if (pauseEnded) {
            std::cout << "     [press ENTER]                 ";
            char c;
            std::cin.get(c);
        }
    }

    static void printTable(std::string name, bool pauseEnded=true) {

        _data_.clear(); // TODO: moze jednak data[name]
        for(Entity item : data[name]) {
            _data_.push_back(item);
        }

        printTableFromData(name, headers[name], pauseEnded);
    }


    static int choiceFromTable(std::string title) {
        while (true) {
            std::string choice;
            std::cout <<  "    do you want to insert new record? (y/n)";
            std::cin >> choice;
            if(choice == "y") {
                data[title].push_back(insertRow(title));
                // return config["autoincrement"][title];
                return config[title];
            }
            else if(choice == "n") {
               printTable(title, false);
               std::string temp;
               std::cout << "     choose id " << title <<":";
               std::cin >> temp;
               return std::stoi(temp);
            }
        }
    }

    static Entity insertRow(std::string title) {
        Entity e;
        std::cout << std::endl;
        std::cout << "     table " << title << " - data entry";
        std::cout << std::endl;

        for (std::string item : headers[title]) {

            if (item == "id") {
                e.setId(System::autoincrement(title));
            }

            else if (item.substr(0, 3) == "id ") {

                // std::string pre = item.substr(0, 3);
                std::string rest = item.substr(3);
                if (rest == "clients") {
                    e.setClientId(choiceFromTable(rest));
                }
                else if(rest == "authors") {
                    e.setIdAuthors(choiceFromTable(rest));
                }

                else if (rest == "books") {
                    e.setBookId(choiceFromTable(rest));
                }
            }
            else {

                std::cout << item << ":";
                std::string input;
                std::getline(std::cin, input);
                std::replace(input.begin(), input.end(), ',', '.');
                if(item == "name") {
                    e.setName(input);
                }
                else if (item == "lastname") {
                    e.setLastname(input);
                }
                else if (item == "pages") {
                    e.setPages(std::stoi(input));
                }
                else if(item == "genres") {
                    e.setGenres(input);
                }
                else if (item == "lend") {
                    e.setBorrowed(input);
                }
                else if (item == "year") {
                    e.setYear(std::stoi(input));
                }

                else if (item == "titles") {
                    e.setTitles(input);
                }
            }
        }
        std::cout << std::endl;
        std::cout << "     finished data entry";
        std::cout << std::endl;

        return e.getEntity();
    }
};

class Books {

    public:

    static void menu() {
        std::string order;
        order = Interface::printInterface("books", {
                "enter",
                "read",
                "read ascending",
                "read descending",
                "read by author",
                "read thicker than",
                "read slimmer than",
                "back"
        });

        if (order == "enter") {
            addBook();
            menu();
        } else if (order == "read") {
            printBooks();
            menu();
        } else if (order == "read ascending") {
            printBooksByColumn();
            menu();
        }
        else if (order == "read descending") {
            printBooksByColumn("descending");
            menu();
        }
        else if (order == "read by author") {
            printBooksByAuthorOnly();
            menu();
        }
        else if (order == "read slimmer than") {
            printBooksBySize();
            menu();
        }
        else if (order == "read thicker than") {
            printBooksBySize("thicker");
            menu();
        }
        else if (order == "back") {
            NULL;
        }
        else {
            Interface::unknownCommandPrompt();
            menu();
        }
    }

    private:

    static void printBooksByColumn(std::string mode="ascending") {
        std::cout << std::endl;
        for (std::string item : headers["books"]) {
            std::cout << "       " << item;
        }
        std::cout << std::endl;
        std::string input;
        std::cout << "     choose column:";
        std::getline(std::cin, input);
        int column = Tables::getColumnIndex("books", input);

        std::vector<std::string> temp;
        _data_.clear();


        for (Entity item : data["books"]){

            std::string text;

            switch(column){
                case 0:
                    text = std::to_string(item.getId());
                    break;
                case 1:
                    text = item.getTitles();
                    break;
                case 2:
                    text = item.getGenres();
                    break;
                case 3:
                    text = std::to_string(item.getYear());
                    break;
                case 4:
                    text = std::to_string(item.getPages());
                    break;
                case 5:
                    text = std::to_string(item.getIdAuthors());
                    break;
            }
            text.append(",");
            text.append(std::to_string(item.getId()));
            temp.push_back(text);

        }
        if (mode == "ascending") {
            std::sort(temp.begin(), temp.end());

        }
        else {
            std::reverse(temp.begin(), temp.end());
        }

        for (std::string item : temp) {
            int i = item.find_first_of(",");
            std::string id = item.substr(i + 1);

            _data_.push_back(Tables::getById("books", std::stoi(id)));
        }
        Interface::printTableFromData("books", headers["books"]);
    }


    static void printBooksBySize(std::string mode="slimmer") {
        std::cout << "Provide number of pages:  ";
        std::string input;
        std::cin >> input;
        _data_.clear();

        for (Entity item : data["books"]) {
            if (mode == "slimmer") {
                if (item.getPages() >= std::stoi(input)) {
                    _data_.push_back(item.getEntity());
                }
            }
            else if (mode == "thicker") {
                if (item.getPages() <= std::stoi(input)) {
                    _data_.push_back(item.getEntity());
                }
            }
        }
        Interface::printTableFromData("books", headers["books"]);
    }

    static void printBooksByAuthorOnly() {
        std::cout << std::endl;
        Interface::printTable("authors", false);
        std::cout << std::endl;
        std::cout << "     provide author's id:";
        int idSearched;
        std::cin >> idSearched;
        _data_.clear();

        for(Entity item: data["books"]) {
            if(item.getIdAuthors() == idSearched) {
                _data_.push_back(item.getEntity());
            }
        }
        // std::cout << getById("authors", idSearched));
        std::string title = "book written by: ";
        title.append(Tables::getById("authors", idSearched).getName());
        title.append(" ");
        title.append(Tables::getById("authors", idSearched).getLastname());
        Interface::printTableFromData(title, headers["books"]);
    }

    static void printBooks() {
        Interface::printTable("books");
    }

    static void addBook() {
        data["books"].push_back(Interface::insertRow("books"));
    }
};

class Clients {

    public:

    static void menu() {
        std::string order;
        order = Interface::printInterface("clients", {"enter", "read", "back"});

        if (order == "enter") {
            addClient();
            menu();
        }
        else if (order == "read") {
            printClients();
            menu();
        }

        else if (order == "back") {
            NULL;
        }

        else {
            Interface::unknownCommandPrompt();
            menu();
        }
    }
    private:

    static void printClients() {
        Interface::printTable("clients");
    }

    static void addClient() {
        data["clients"].push_back(Interface::insertRow("clients"));
    }

};

class Orders {

    public:

    static void menu() {

        std::string order;
        order = Interface::printInterface("oders", {"enter", "read", "back", "read not borrowed"});

        if (order == "enter") {
            addOrder();
            menu();
        }
        else if (order == "read") {
            printOrders();
            menu();
        }
        else if (order == "read not lend") {
            printAvailableBooks();
            menu();
        }
        else if (order == "back") {
            NULL;
        }
        else {
            Interface::unknownCommandPrompt();
            menu();
        }
    }

    private:

    static void printOrders() {
        Interface::printTable("orders");
    }

    static void printAvailableBooks() {

    }

    static void addOrder() {
        data["orders"].push_back(Interface::insertRow("orders"));
    }
};

class Authors {
    public:
    static void menu() {
        std::string order;
        order = Interface::printInterface("authors", {"enter", "read", "back"});
        if (order == "enter") {
            addAuthor();
            menu();
        }
        else if (order == "read") {
            printAuthors();
            menu();
        }
        else if (order == "back") {
            NULL;
        }
        else {
            Interface::unknownCommandPrompt();
            menu();
        }
    }
    private:
    static void printAuthors() {
        Interface::printTable("authors");
    }

    static void addAuthor() {
        data["authors"].push_back(Interface::insertRow("authors"));
    }
};


void menu() {
    std::string order;
    order = Interface::printInterface("Main menu", {"books", "authors", "clients", "orders", "exit"});
    if (order == "books") {
        Books::menu();
    }
    else if (order == "authors") {
        Authors::menu();
    }
    else if (order == "clients") {
        Clients::menu();
    }
    else if (order == "orders") {
        Orders::menu();
    }
    else if(order == "exit") {
        System::quitting();
    }
    else {
        Interface::unknownCommandPrompt();
    }
}

int main() {

    System::boot();
    while(true) {
        std::cout << "WARNING! data write occurs after providing 'exit' command" << std::endl;
        menu();
    }
}
