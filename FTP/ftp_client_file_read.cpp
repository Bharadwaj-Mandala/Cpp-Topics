#include <iostream>
#include <string>
#include <curl/curl.h>

// Callback function to handle incoming data stream
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t totalSize = size * nmemb;
    std::string *buffer = static_cast<std::string *>(userp);
    buffer->append(static_cast<char *>(contents), totalSize);
    return totalSize;
}

int main()
{
    CURL *curl;
    CURLcode res;
    std::string fileContents;

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl)
    {
        // Build the complete FTP URL: ftp://username:password@hostname/path/to/file.txt
        // Alternatively, use CURLOPT_USERNAME and CURLOPT_PASSWORD options
        std::string ftpUrl = "ftp://admin:admin@localhost/Files/test.txt";

        curl_easy_setopt(curl, CURLOPT_URL, ftpUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_USERPWD, "admin:admin");

        // Pass the callback function to handle data data packets
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // Pass the string object target where the data will be appended
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &fileContents);

        // Optional: Switch to Active mode if Passive mode fails (Default is Passive)
        // curl_easy_setopt(curl, CURLOPT_FTPPORT, "-");

        // Execute the FTP download request
        res = curl_easy_perform(curl);

        // Validate the execution status
        if (res != CURLE_OK)
        {
            std::cerr << "FTP Request Failed: " << curl_easy_strerror(res) << std::endl;
        }
        else
        {
            std::cout << "File Read Successfully!\n--- File Contents ---\n";
            std::cout << fileContents << "\n---------------------" << std::endl;
        }

        // Clean up easy handle
        curl_easy_cleanup(curl);
    }

    // Clean up global environment
    curl_global_cleanup();
    return 0;
}
