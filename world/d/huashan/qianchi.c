// qianchi.c

inherit ROOM;

void create()
{
        set("short", "ǧ�ߴ�");
        set("long", @LONG
ǰ����һб���촹ʯ�ݵ�ɽ�ף�����Ǻպ�������ǧ�ߴ���ǧ�ߴ���
��һ�����Ҽ����ѷ쿪����ɣ�б��Լ��ʮ�ȣ���Լ��ʮ�ף�����һ����
�䡣������Ǿ���ʮ�㣬���ǲ�Ҫð���ʵǵĺá�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"qingke",
  "southup" : __DIR__"baichi",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}

int valid_leave(object me, string dir)
{
    
	if (dir == "southup") 
	{
	        if  ((int)me->query_skill("dodge", 1) < 30 )
        	{
        	        me->add("gin", -10);
                	me->add("kee", -10);
                        if ( me->query("combat_exp") >= me->query_skill("dodge", 1) * me->query_skill("dodge", 1) * me->query_skill("dodge", 1) / 10 )
				me->improve_skill("dodge", me->query("int"));
        	}
	}
        return 1;
}
