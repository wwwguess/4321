// keeper.c

inherit ITEM;

void init()
{
	add_action("do_put", "juan");}
void create()
{
	set_name("��\����", ({ "denotation box", "box" }) );
	set("unit", "��");
	set("long",
		"�����������������Ů��������Ǯ�Ĺ�\���䣬����԰�����Ǯ\n"
		"�Ž�ȥ��\n");
	set("value", 1);
	set("no_get", 1);
	set_max_encumbrance(10000);
}

int
 do_put(string arg)
{
	int val;
	object who,ob;
        if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ��ʲ����Ʒ��\n");
            ob = present(arg, this_player());

	val=ob->value();
       who=this_player();
	//if( !who = this_player() ) return;

	//if( !val  ) return;

	//if( val > 100 ) {
	//	if (who->query("bellicosity") > 0)
	//	&&	(random(val/10) > (int)who->query("kar")) )
			who->add("bellicosity", - (val/10) );
                      val=val/10;
               write(who->name()+"��ɱ��������"+val+"��.\n");	

	seteuid(getuid());
	destruct(ob);
 return 1;
}
