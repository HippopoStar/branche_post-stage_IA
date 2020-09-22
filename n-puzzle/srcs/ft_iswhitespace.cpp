bool		ft_iswhitespace(const char c)
{
	return ((c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ') ? true : false);
}
