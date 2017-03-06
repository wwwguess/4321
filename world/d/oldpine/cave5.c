// Room: /d/oldpine/cave5.c

inherit ROOM;

string look_wall ();

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
�������Ѿ�����ɽ�������, Ү...������Ƕ�����, ��������
�������ٲ���ˮ��, ��ϸ�Ĺ۲�ʯ��(wall), ���Է���������һЩ����
����̵���....
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"waterfall",
		]));

	set("item_desc", ([
		"wall" : (: look_wall :),
		]) );

	set("objects", ([
		__DIR__"npc/skeleton":	1,
		]) );

	setup();
}

void init ()
{
	add_action ("do_bury", "bury");
}

int do_bury (string arg)
{
	object obbook, obsk;
	int ikar;
 
        if( !arg ) return notify_fail("��Ҫ��ʲô��\n");
        if( arg != "skeleton" || !objectp(obsk = present(arg, environment(this_player()))) )
                return notify_fail("����û������������\n");

	message_vision ("$NС�������������Ǿߺ��ǡ�\n",this_player());

	obsk->move("/obj/void");

	ikar = (int ) random((int) (this_player()->query("kar"))+10); 
	if (ikar > 25) { 
		message_vision("$N����ɽ��������ʯ�ڡ���������һ���죬һ����׹��������\n", this_player());
		obbook = new(__DIR__"npc/obj/parrybook");
		obbook->move(__DIR__"cave5");
		return 1;
		}
	    else if (ikar > 20) 
		message_vision("$Nֻ����ɽ�������׷�����Ʈ�¼���ֽƬ����\n",this_player());
			
	message_vision ("$N���á��䡹��һ���죬�Ѿ�����ˤ����ȥ\n", this_player());
	this_player()->move(__DIR__"waterfall");
	
	return 1;
}

string look_wall ()
{
	return ("�Ϸ���Σˮ, ��������ˮ�̸��峤���е�һ����,
һ��������ѧ, ����а����ɽ����֮����, ΪӪ��������С�˰���,
����ڴˡ����Ӻ����ɷ�������ϧ, ֻ�ɺ�һ����ѧ���޴���!
��(bury)���Ź����Ϸ����Թ���Ҫּ, ��......
");
} 
