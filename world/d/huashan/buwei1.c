// square.c1.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ǻ�ɽ��������Ⱥ�ľ�����������Ϊ�������˴���ǰ�������Ϲ���
�������á������Ҷ���кܿ���ȴûʲô���裬��ǽ�������ѽ��Σ�
����������Ⱥ���¡���ͽ�ĵط��������ǻ�԰��
LONG
        );
        set("valid_startroom", 1);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"square",
  "south" : __DIR__"houhuayuan1",
]));
        set("objects", ([
                CLASS_D("huashan") + "/dayou" : 1,
                CLASS_D("huashan") + "/yueling" : 1]));
        setup();
        set("no_clean_up", 0);
        setup();
        "/obj/board/huashan_b"->foo();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
	object obj;
        myfam = (mapping)me->query("family");
	if (objectp((obj=present("lu dayou", environment(me)))))
	{	
        	if ((!myfam || myfam["family_name"] != "��ɽ��") && dir == "south"&&
		obj->query_temp("block_msg/all")==0)
	                return notify_fail("½���Ѻȵ����㲻�ǻ�ɽ���ӣ��������ڡ�\n");
	}
        return ::valid_leave(me, dir);
}
