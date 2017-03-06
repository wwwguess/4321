// Room: /d/oldpine/cliffside.c

inherit ROOM;

void create()
{
	set("short", "�ּ�....��....���±�");
	set("long", @LONG
��������վ��һ�������ּ��С�յ��ϣ���ı��ߡ����ߡ��ϱ߶�
��ï�ܵ�������Ψ�������Ǹ�����(cliff)������̽ͷһ�������̲���
�����ص���һ��������������ɵ�ǧ��С�ģ�һ��С�ĵ�����ȥ�϶���
������ǡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"pine" + (random(6)+1),
  "north" : __DIR__"pine" + (random(6)+1),
  "east" : __DIR__"pine" + (random(6)+1),
  "west" : __DIR__"pine" + (random(6)+1),
  "northeast" : __DIR__"pine7",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "cliff" : "�㶨������һ������ʵ�������û����������ô�ֲ���Ҳ��\��
���Դ���������ɽ����ֻ���������ϴ��û�����ְ׳�Ը���
����ɵ�°ɡ�
",
]));
	set("outdoors", "oldpine");

	setup();
//	replace_program(ROOM);
}
void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        if( !arg || arg!="down" ) return 0;

        message_vision("$Nһ������ı��飬��ʼС�����������ʯ��������ȥ��\n",
                this_player() );
        this_player()->move(__DIR__"cliff2");

        return 1;
}

