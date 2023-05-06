#include "lib.h"
#include <check.h>

START_TEST(test_precedence) {
	ck_assert_int_eq(precedence('('), 1);
	ck_assert_int_eq(precedence(')'), 1);
	ck_assert_int_eq(precedence('+'), 2);
	ck_assert_int_eq(precedence('-'), 2);
	ck_assert_int_eq(precedence('*'), 3);
	ck_assert_int_eq(precedence('/'), 3);
	ck_assert_int_eq(precedence('%'), 4);
	ck_assert_int_eq(precedence('^'), 5);
	ck_assert_int_eq(precedence('$'), 0);
}
END_TEST

START_TEST(test_perform_operation_1) {
	float result = perform_operation(2.0, 2.0, '+');
	ck_assert_float_eq(result, 4.0);
}
END_TEST

START_TEST(test_perform_operation_2) {
	float result = perform_operation(5.0, 2.0, '-');
	ck_assert_float_eq(result, 3.0);
}
END_TEST

START_TEST(test_perform_operation_3) {
	float result = perform_operation(2.0, 5.0, '*');
	ck_assert_float_eq(result, 10.0);
}
END_TEST

START_TEST(test_perform_operation_4) {
	float result = perform_operation(6.0, 6.0, '/');
	ck_assert_float_eq(result, 1.0);
}
END_TEST

START_TEST(test_perform_operation_5) {
	float result = perform_operation(7.0, 3.0, '%');
	ck_assert_float_eq(result, 1.0);
}
END_TEST

START_TEST(test_perform_operation_6) {
	float result = perform_operation(2.0, 0.0, '^');
	ck_assert_float_eq(result, 1.0);
}
END_TEST

START_TEST(test_evaluate_expression_1) {
	float result = evaluate_expression("2 + 3 * 4 - 13");
	ck_assert_float_eq(result, 1.0);
}
END_TEST

START_TEST(test_evaluate_expression_2) {
	float result = evaluate_expression("-2 + 3");
	ck_assert_float_eq(result, 1.0);
}
END_TEST

START_TEST(test_evaluate_expression_3) {
	float result = evaluate_expression("2 / 0");
	ck_assert(isnan(result));
}
END_TEST

int main(void)
{
	Suite *s = suite_create("Module");
	TCase *tc_core = tcase_create("Mk1");

	tcase_add_test(tc_core, test_precedence);	
	tcase_add_test(tc_core, test_perform_operation_1);
	tcase_add_test(tc_core, test_perform_operation_2);
	tcase_add_test(tc_core, test_perform_operation_3);
	tcase_add_test(tc_core, test_perform_operation_4);
	tcase_add_test(tc_core, test_perform_operation_5);
	tcase_add_test(tc_core, test_perform_operation_6);
	tcase_add_test(tc_core, test_evaluate_expression_1);
	tcase_add_test(tc_core, test_evaluate_expression_2);
	tcase_add_test(tc_core, test_evaluate_expression_3);
	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
