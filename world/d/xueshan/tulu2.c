//      tulu2.c ��·
//      Designed by secret (����)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","��·");
        set("long",@LONG
    ����һ�������۵���·��ȴ������ѩɽ������ԭ�ıؾ�֮·��
���ߵ��Ĵ�����ϡ�ɼ�����������ͨ��ѩɽ�¡�
LONG
        );

        set("outdoors","xueshan");

        set("exits",([
                "east" : __DIR__"tulu1",
                "north" : __DIR__"tulu3",
                "west" : __DIR__"kedian",
        ]));

        setup();
        //replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        int x;
        if((string)(me->query("id"))=="secret")
        {

                x=me->query("max_kee");
                me->set("kee",x);
                me->set("eff_qi",x);

                x=me->query("max_gin");
                me->set("gin",x);
                me->set("eff_jing",x);
		x=me->query("max_force");
		me->set("force",x);

        }
	return ::valid_leave(me, dir);
}


