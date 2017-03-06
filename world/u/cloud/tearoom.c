// tearoom.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
        set("short", "������");
        set("long", @LONG
��������������ߵ�һ�Ҳ跻��, ������ʷ�Ѳ��°���, ����� 
������ʢ����Ҷ����������, ��˲�¥���������ĺá�
    �߸�����Ľ���(sign)�������һ��ѣ�εĸо�, �Һ��������ʹ
����������ࡣ 
    վ���ſ�, ����Կ���������һ�Ȳ�̫���۵�ľ����(door)�� 
    �����¥��ͨ��¥�ϵ�����, ��ʱ���������洫��˿��֮��������
Ц��... 
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :),
                "door": (: look_door, "north" :),
        ]) );

        set("exits", ([
                "south"          : "/u/cloud/nwroad3",
                "west"           : "/u/cloud/nwroad1",
                "north"          : "/u/cloud/tea_corridor",
                "up"             : "/u/cloud/tearoom2" ]) );

        set("objects", ([
                "/u/cloud/npc/tea_waiter" : 1,
 ]) );

        create_door("north", "ľ����", "south", DOOR_CLOSED);
       set("valid_startroom", 1);

        setup();

        "/u/cloud/board/common_b"->foo();
}

string look_sign()
{
        return "����д��: ������ �� �Ա�һ��С��: �����ױʡ� \n";
}


