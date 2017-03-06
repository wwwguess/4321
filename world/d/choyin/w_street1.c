// Room: /d/choyin/w_street1.c

inherit ROOM;

int do_lift (string arg);
int do_check ();

void create()
{
        set("short", "�����");
        set("long", @LONG
�����������سǵ�����֣����߾����سǵ����ţ�һ���޴����¥
�Ͽ��������š����֣�������һ��С��ϱ�����һ���������ֵ�����
����һ��ʯʨ(statue)��������վ���ģ����������˷�Ϊ����������
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "statue" : 
"����ʯʨ��һ��Ѱ���˼ҷ����ſ���լ��а��ʯʨ���в�ͬ����������
���ģ����Ҵ�СҪ��öֻ࣬���м�����أ�����û����˭�ܾ�������
��ע�⵽ʯʨ�Ķ�ͷ�Ͽ���һ���������֣���֪�Ǻ����⣿
",
]));
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"w_street2",
]));
        set("no_clean_up", 0);
        set("outdoors", "choyin");

        setup();
}

void init()
{
        add_action ("do_lift", "lift");
	add_action ("do_check", "check");
}

void do_check()
{
	printf("%s\n", query("liftid"));
}

void check_trigger()
{
	object me ;
	me = this_player();

        if  ((int) query("lift_trigger") + me->query("str")/5 >= 10) {
                message("vision", "ʯʨ�Ӿ�Ȼ�����ƶ��˳���©�����µĶ�Ѩ��\n"+
"$N�Ӷ��ڵ�����ȥ��\n",environment(me),({ me }) );
		me->move(__DIR__"lionroom");
                message_vision ("$Nʯʨ���ֻ����������ƶ��˳������ø�ס���ڡ�\n", me);
		set("liftid", me->query("id"));
                }
}

int do_lift (string arg)
{
	string id ;
	object ob;

        if (arg != "statue")
                return notify_fail("��Ҫ��ʲô��\n");

        message_vision ("$NŬ����̧��ʯʨ�ӣ���ͼ̧��һ��㡣\n", this_player())
;
	id = (string) query("liftid");
/*	if ( id && ( id != (string)this_player()->query("id")) ) 
		return 1 ;
*/
	if ( id ) {
		ob = find_player(id);
		if ( ob && (environment(ob)->query("short") == "���ض�Ѩ"))
		return 1;
		}

 	if ( !id ) set("liftid",(string)this_player()->query("id"));

        add("lift_trigger", 1);
        check_trigger();
        return 1;
}

/*int valid_leave(object me,string dir)
{
	if ( ::valid_leave(me,dir) ) {
		delete("liftid");
		delete("lift_trigger");
	}
	return 1;
}
*/
void reset()
{
        delete("lift_trigger");
	delete("liftid");
        ::reset();
}

