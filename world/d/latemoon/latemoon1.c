#include <room.h>

inherit ROOM;

void create()
{
	set("short","����ׯ����");
	set("long", @LONG
�߽�������̧ͷӭ�濴������һ���Ϻ�����ᣣ�һ�����罫����
�����������룬�������������������̴�񰸣�����һɫ������֬��ƿ��
ƿ�в����ۺ�Ĵ���ĵ������̴���м��ֶ������߳������Ļ��ᣬ��ʽ
���޳��㣬��ë���࣬��������������Ҫ�ӻ�ֽ�Ϸɳ�����Ϸ�ڴ���֮��
��������еĸ�������֮��͸��һ������������ȴҲ��һ�㸻���˼һ��
���ӹ֬�׷�֮����
    �������Եİ�ʯǶ�����Ϲ����ؿ���һ������д����

    ���������������£�ȴ����������Ϊ����;
      ��ǰƮ�����ϼ����֪���£�������������

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" :__DIR__"front_yard",
		"north" :__DIR__"latemoon3",
		"west" :__DIR__"latemoonc",
	]));

	set("objects",([
        __DIR__"npc/servant" : 2,
		CLASS_D("dancer") + "/master" : 1 ]) );
	set("valid_startroom", 1);
	setup();
	call_other("/obj/board/dancer_b", "???");
	replace_program(ROOM);
}
