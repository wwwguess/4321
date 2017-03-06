inherit ROOM;
void create()
{
	set("short","������");
	set("long", @LONG
�ذ�����ˮĥʯ�̳ɡ�����ǽ�Ϲ��������ֻ���
�����ǽ�ϸ߸ߵع���һ����ң����顰�����á�
���֡�������һ��̫ʦ��.
LONG
	);
	set("exits", ([
		"out" : __DIR__ "qlt1",
	]));
	set("valid_startroom", 1);
	setup();
}
void init()
{
add_action("do_age","age");
add_action("do_jiang","jiang");
add_action("do_exp","exp");
add_action("do_3","3");
add_action("do_2","2");
add_action("do_1","1");
}
int do_1()
{
object obj;
this_player()->add("max_force",1);
this_player()->set("force",this_player()->query("max_force")*2 );
this_player()->set("kee",this_player()->query("max_kee"));
this_player()->set("sen",this_player()->query("max_sen") );
obj=new("/obj/money/gold");
obj->move( this_player() );
this_player()->set("gin",this_player()->query("max_gin"));
return 1;
}

int do_2()
{
this_player()->add("potential",12);
return 1;
}

int do_3()
{
this_player()->set("max_kee",this_player()->query("eff_kee"));
return 1;
}

int do_exp()
{
this_player()->add("combat_exp",231);
this_player()->add("max_age",40000);
return 1;
}

int do_jiang()
{
this_player()->add("potential",-53);
return 1;
}

int do_age()
{
this_player()->add("mud_age",3600);
return 1;
}

