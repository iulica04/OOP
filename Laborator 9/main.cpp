#include "Csv.h"

int main() {
    std::ifstream input_file("episodes.csv");
    if (!input_file.is_open()) {
        printf("File couldn't be opened\n");
        return 1;
    }
    CsvReader reader(input_file);

    std::vector<Episode> episodes;

    for (std::vector<std::string> columns : reader) {
        // Transform the columns into an Episode and push it in a vector
        Episode episode;
        episode.title = columns[0];
        episode.date = columns[1];
        episode.length = columns[2];
        episode.viewersmm = columns[3];
        episode.score = columns[4];
        episodes.push_back(episode);
    }

    printf("number of episodes: %zu\n\n", episodes.size());

    std::ofstream output_file("output.txt");

   
    for (auto& [title, date, length, viewersmm, score] : episodes) {
        // Pretty print the episode in the output file

        output_file << "The title is: " << title << std::endl;
        output_file << "The date is: " << date << std::endl;
        output_file << "The length is: " << length << std::endl;
        output_file << "The viewersmm is: " << viewersmm << std::endl;
        output_file << "The score is: " << score << std::endl;
        output_file << std::endl;
    }
}
