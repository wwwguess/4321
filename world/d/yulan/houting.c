#include <room.h>

inherit ROOM;

void create()
{
        set("short","����ɽׯ�����");
        set("long", @LONG
�߽�������̧ͷӭ�濴������һ��ۺ�����ᣣ��������������������
̴�񰸣�����һɫ����ƿ��ƿ�в����ۺ�Ĵ����һ�����̴���м���
�������߳������Ļ��ᣬ�ű߷���һ�����ܣ������Ϸ���һ�ѱ��������
���еĸ�������֮��͸��һ��Ӣ����

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "north" :__DIR__"yulanc",
        ]));

        setup();
        replace_program(ROOM);
}
