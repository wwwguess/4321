// Room: /d/canyon/bamboo/bamboo3.c

inherit ROOM;

void create()
{
	set("short", "���ֵ�");
	set("long", @LONG
������һ�����ʯ��סȥ·����������������Ӵ��ʯ��������
�����������ֲ��죬�ڴ˳�һ�밼�ͣ�����Χס�˱�����ȥ·������
һ�������������ǵ��ƿ���޴�Ļ�ʯ���У�����������ǿ�����ܵ�
���ӷ��������˵��������ݷ���˲�Ҫ�������˵�֮���˿��Ʋ���ӭ
�������ιۡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"bamboo2",
]));

	setup();
}

void init ()
{
	add_action("do_move","move");
	add_action("do_enter","enter");
	add_action("go_enter","go");
}
int do_move(string arg)
{
	object me;
	
	if ( arg!="stone" ) return 0;
	
	me=this_player();
	
	if ( ((int)me->query("force") < 560) ||
	     ((int)me->query("max_force") < 560) ||
	     ((int)me->query("force_factor") < 40 ) ) { 
		tell_object(me, "�������̫��ร�\n");
		return 1;
	}

	me->receive_damage("gin",20);
	me->receive_damage("kee",60);
	me->receive_damage("sen",20);
	
	if( query("exits/enter") ) return 1;
	
	set("exits/enter",__DIR__"train");
        message_vision("$N�����ʯ������������ƶ�����������һ��СС��϶�졣\n"
        		,me);
	return 1;
}

int do_enter()
{
	if( !query("exits/enter") ) return 0;
	
	message_vision("��$Nͨ��϶�죬���ʯ�ּ��ٵغϱա�\n",this_player());
	delete("exits/enter");
	this_player()->move(__DIR__"train");
	return 1;
}

int go_enter(string arg)
{
	if( !query("exits/enter") ) return 0;
	        
	if( arg!="enter" ) return 0;
	
	message_vision("��$Nͨ��϶�죬���ʯ�ּ��ٵغϱա�\n",this_player());
	delete("exits/enter");
	this_player()->move(__DIR__"train");
	return 1;
}
