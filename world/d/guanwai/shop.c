
#include <room.h>
inherit "/std/room/hockshop";
//inherit "/std/room/bank.c";

void create()
{
	set("short", "ӥ���̺�");
	set("long", @LONG
ӥ��һ��������׿�������ⶦʢ���̺š��Ӳض����Ĳ��㣬�ӹ������Ĵ�
����˿�У��Ӵ��¯���Ĳ�ש������ʲô��ֻҪ��ֵǮ�Ķ�����������������
��������̨�Ϸ���һ������(sign)��
LONG
	);
	set("item_desc", ([
		"sign": @TEXT
���̺Ų����ۺ񡣿��Ŀ���������䵱(pawn)������(sell)���ֻ��
ͭǮ���������ƽ���Ʊһ��ͨ�á����̺Ż����Ϊ���Ķһ�(convert)Ǯ�ҡ�
TEXT
	]) );
	set("exits", ([
		"west" : __DIR__"octo15",
	]));
        set("objects", ([
                __DIR__"npc/puying": 1 ]) );

	setup();

}
