// Room: /d/oldpine/pine1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������վ��һ�����������....����һ��������....����֪��
��ô�࣬ï�ܵ������ڱ���������գ�ʹ��������Ū������������
���֮ǰ�Ͻ��ҵ�·����ȥ�ɡ�
LONG
	);
	set("outdoors", "oldpine");

	// Because setup() calls reset(), so we don't need initialize
	// our exits here.
	setup();
}

void reset()
{
	::reset();
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"pine" + (random(5)+2),
	///  "north" : __DIR__"pine" + (random(6)+1),
	  "north" :__DIR__"pine6", 
          "west" : __DIR__"pine" + (random(5)+2),
	  "east" : __DIR__"pine" + (random(5)+2),
	]));
}

int valid_leave(object me, string dir)
{
	write("��ʵ��Ū���������....");
	switch(dir) {
		case "north":	write("����....�����������أ�....");	break;
		case "east":	write("����....����....");	break;
		case "south":	write("�ϱ�....�������ϱߣ�....");	break;
		case "west":	write("����....��....");	break;
		default:
			write("������������....");
	}
	write("�����������ɡ�\n");
	return 1;
}
