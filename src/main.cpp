#include "main.h"

int main(int argc, char *argv[])
{
    std::cout << NAME << "\n\n\n\n";

    // initialize precalculated lookup tables
    init_leapers_attacks();
    init_sliders_attacks();

    // initialize psqt
    init_pesto_tables();

    // runs the bench test if we have a bench command
    if (argc >= 2)
    {
        // std::cout << "|" << argv[1] << "|";
        if (!strcmp(argv[1], "bench"))
        {
            // creates a dummy searcher
            Board board(start_position);
            std::vector<Move> move_list;
            Searcher searcher(board, move_list, UINT64_MAX);

            searcher.bench();
            return 0;
        }
    }

    Board board("r1bqkbnr/pppp1ppp/8/4n3/4P3/2N5/PPPP1PPP/R1BQKB1R b KQkq - 1 4");
    std::cout << (int)board.side_to_move;
    std::cout
        << evaluate(board);

    // UCI_loop();

    // Board board("rnb1kbnr/2q5/1p3p1p/p3p1P1/P6p/BPP4P/3P1P2/RN1QKB1R b KQkq - 0 17");
    // Move move(h6, g5, CAPTURES);
    // board.make_move(move);
    // print_bitboard(board.bitboard(WHITE_PAWN));

    // Board board("5b1r/3k4/1Q1P1ppp/5q2/3p4/8/5PPP/1N2K1NR w K - 0 27");
    // perft_debug(board, 1, 1);

    return 0;
}