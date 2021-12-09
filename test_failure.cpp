

void test_failure()
{
    static_assert((1 + 1) == 2, "Test success");
}

int main(int argc, char const *argv[])
{
    test_failure();
    return 0;
}
