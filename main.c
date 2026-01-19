int	main()
{
	t_stack *a = NULL;

	ft_stack_add(&a, ft_stack_new(10));
	ft_stack_add(&a, ft_stack_new(20));
	ft_stack_add(&a, ft_stack_new(30));

	print_stack(a, NULL);
	return (0);
}
