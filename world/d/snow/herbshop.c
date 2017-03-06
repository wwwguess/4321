// Room: /d/snow/herbshop.c

inherit ROOM;

void create()
{
	set("short", "ɣ��ҩ��");
	set("long", @LONG
������һ���ģ��С��ҩ�̣���ֵ��ǣ����������Ų���һ˿ҩ��
Ӧ�е�ҩζ���е�ֻ��һ�ɵ�����̴�㣬���˾����Ŀ�������ҩ�̵Ĺ�
̨���ڵ��̿�����һ�棬��̨����һ���޴��ҩ��(cabinet)�� �����
С����ֻ�����ߡ��˰ٸ�֮�࣬����ȫ��û������ǩ��ҩ�̵ĳ����ڶ�
�ߣ���̨������һ�ŷ��Ƶ�ֽƬ(sign)��
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
		"cabinet" : @TEXT
һ���޴��ɼľҩ�񣬴�������ɫ�����������ĥ�÷����ĺۼ���
���ҩ���������൱��Զ�ˣ���һ���������ǣ�ҩ���ǽ���ƺ���
�÷ǳ����ܣ�������˿����϶��
TEXT
		,
		"sign": "ֽƬ��д������Ŀ������ list ���ƹ��ѯ��\n",
]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"mstreet3",
	]));
	set("objects", ([
		__DIR__"npc/herbalist": 1,
		__DIR__"npc/woodcutter": 1,
	]) );
	set("no_fight",1);
	set("no_steal",1);
	setup();
	replace_program(ROOM);
}
