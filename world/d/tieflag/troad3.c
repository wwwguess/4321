//troad3
inherit ROOM;

void create()
{
        set("short", "Σ��ǰ");
        set("long", @LONG
С·����ͻȻ�жϣ�һ��Σ�µ�ס���ȥ·����������(tree)���� ���Ե���Ϊ�Ź֡�
һֻͨ��ѩ�׵Ĳ�˹è���ڵ���һ��������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"troad2",
]));
        set("objects", ([
        __DIR__"npc/cat" : 1,
                        ]) ); 
        set("item_desc", ([
                "tree": "���������(tree)���ܣ��ƺ������˹����á�\n",
                "����": "���������(tree)���ܣ��ƺ������˹����á�\n" 
	]) );
        
	set("outdoors","tieflag"); 	
        setup();
}
void init()
{
        add_action("do_west", "w");
        add_action("do_west", "west");
}
int do_west(string arg)
{
	object me;
	object room;
	me = this_player();
	if(me->query_temp("mark/cat"))
        {       
		me->delete_temp("mark/cat");
		message_vision("$N�ƿ��������������һ��ɽ�����˽�ȥ��\n", me);
		room = load_object(__DIR__"dong0");
		if(room) me->move(room);
		return 1;
	}
	return 0;
}

