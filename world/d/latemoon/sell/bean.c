inherit COMBINED_ITEM;

void create()
{
	set_name("�ɶ�", ({"sen-bean"}));
	set("long",	"����һ���е���ֵĶ��ӣ���������һ���ϵ�ҩ�ĵ�ζ����\n");
	set("unit", "��");
	set("base_unit", "��");
	set("base_weight", 200);
	set_amount(1);
}

void init()
{
	if( this_player()==environment() )
		add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	if( !arg || arg != "sen-bean")  return notify_fail("��Ҫ����ô��? \n");

	message_vision(
	   "$N�ó�һ��С���ӣ�һ�ڸ�������ȥ��\n"
	   "ֻ��$N���Ϸ���һ����Σ������˿������ö���! \n",this_player()  );
	this_player()->receive_heal("gin", 50);
	this_player()->receive_heal("kee", 100);
	this_player()->receive_heal("sen", 50);

	add_amount(-1);
	return 1;
}
