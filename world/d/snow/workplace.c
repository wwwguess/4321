#include <dbase.h>
#include <room.h>

inherit ROOM;
 
string look_sign ();

void create ()
{
	set ("short","����ӹ���");
	set ("long", @LONG
����һ�����ӹ����������ǹ����ѿǳ��׵ĵط����׳��ϰ���һ��һ
����֪����ʮ�־����ĸ��ݵ������ˣ����Ǵ���һ����Ц������Կ���
���������ææµµ�Ĺ����ţ��ſڹ���һ������(sign)��������ͨ��
ѩͤ���ֵĴ��š�
LONG
	);
	
	set ("no_fight", 1);
	set ("item_desc", ([
		"sign": (:look_sign :),
	]) );

	set ("exits", ([
		"west"		: "/d/snow/mstreet2" ]));

	setup ();
}

void init ()
{
	add_action ("do_work", "work");
}

int do_work ()
{
	object me;
        object silver;

	me = this_player ();
	
        if((int)me->query("gin")<30 || (int)me->query("sen")<30)
                return notify_fail (
			"��ľ���̫����,���ڲ��ܹ���.\n");
	
	printf("
������Ĺ������ڽ����ˣ�����Ҳ�۵�Ҫ��
�ϰ����˵��������Ĺ�Ǯ��
");

	me->receive_damage( "sen", 30 );
	me->receive_damage( "gin", 30 );
 	silver=new(SILVER_OB);
	silver->set_amount(2);
	silver->move(me);
//	destruct(silver);
	return 1;
}
		
string look_sign ()
{
	return "\n��������ȱ���֣������Ӷһ���̹����ɻ
		\nwork     ��ʼ������\n";
}
