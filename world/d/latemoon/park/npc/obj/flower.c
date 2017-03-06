inherit COMBINED_ITEM;

void create()
{
    set_name("С����", ({ "pistil" }));
    set("long", "����һ����ɫ�����ػ����һ�ֵ���������\n");
    set("unit", "��");
    set("base_unit", "��");
    set("base_weight", 20);
	set_amount(1);
}

void init()
{
	if( this_player()==environment() )
		add_action("do_eat", "eat");
}

int do_eat(string arg)
{
    int I,J;
    object me;

    me = this_player();
    J = me->query_condition("rose_poison");
    if ( J < 10)  I = 0;
    if ( J >= 10) I = J - 10;
    if( !arg || arg != "pistil" ) return notify_fail("��Ҫ����ô��? \n");

	message_vision(
       "$N�ó�һ��С���һ�ڸ�������ȥ��\n"
       "ֻ��$N���Ϸ���һ����Σ������˿������ö���! \n",me );
    me->receive_heal("sen", 50);
    me->apply_condition("rose_poison", I);

	add_amount(-1);
	return 1;
}
