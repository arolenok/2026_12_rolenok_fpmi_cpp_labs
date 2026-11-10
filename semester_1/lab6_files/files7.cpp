#include <ctime>
#include <format>
#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
//var7

static void compress(const std::string&, std::string&);
static void writeLog(std::ofstream&, const std::string&);

int main() {
    std::string str, result, output = "output.txt", input = "input.txt", log = "log.txt";
    std::ofstream olog(log);
    if (!olog.is_open()) {
        std::cerr << std::format("ERROR: couldn't open \"{}\"", log) << '\n';
        return 3;
    }
    writeLog(olog, std::format("opened \"{}\"", log));

    writeLog(olog, std::format("opening \"{}\"", input));
    std::ifstream in(input);
    if (!in.is_open()) {
        writeLog(olog, std::format("ERROR: couldn't open \"{}\"", input));
        writeLog(olog, "finished program with code 1");
        olog.close();
        return 1;
    }
    writeLog(olog, std::format("opened \"{}\"", input));

    writeLog(olog, std::format("opening \"{}\"", output));
    std::ofstream out(output);
    if (!out.is_open()) {
        writeLog(olog, std::format("ERROR: couldn't open \"{}\"", output));
        in.close();
        writeLog(olog, std::format("closed file \"{}\"", input));
        writeLog(olog, "finished program with code 2");
        olog.close();
        return 2;
    }
    writeLog(olog, std::format("opened \"{}\"", output));

    writeLog(olog, std::format("reading lines from \"{}\"", input));
    while (std::getline(in, str)) {
        writeLog(olog, std::format("got line: \"{}\"", str));
        result.clear();
        writeLog(olog, std::format("transforming line \"{}\"", str));
        compress(str, result);
        writeLog(olog, std::format(R"(transformed line "{}" to "{}")", str, result));
        out << result << '\n';
        writeLog(olog, std::format(R"(wrote line "{}" to "{}")", result, output));
    }

    in.close();
    writeLog(olog, std::format("closed file \"{}\"", input));
    out.close();
    writeLog(olog, std::format("closed file \"{}\"", output));
    writeLog(olog, "finished program with code 0");
    olog.close();
    return 0;
}

static void compress(const std::string& str, std::string& result) {
    int counter = 0;
    const int len = static_cast<int>(str.length());
    for (int i = 0; i < len; ++i) {
        counter = 1;
        while (i < len - 1 && str[i] == str[i + 1]) {
            counter++;
            i++;
        }
        if (counter > 1) {
            result += str[i];
            result += std::to_string(counter);
        }
        else {
            result += str[i];
        }
    }
}

static void writeLog(std::ofstream& olog, const std::string& message) {
    std::time_t t = std::time(nullptr);
    olog << std::put_time(std::localtime(&t), "%d.%m.%Y %H:%M:%S") << " | " << message << std::endl;
}