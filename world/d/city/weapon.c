// weapon.c
#include <room.h>
inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "��ʦ������");
        set("long", @LONG
�����ǽ����������������ľ�ʦ�����ꡣ���̿�����ש�̵ء�
���ܵ�ǽ���Ϲ����˸�ʽ�ĵ��������ߵ��������ϵ�ǹꪵķ�����
���������ۡ�����ǽ�Ĵ��̨һ����Ⱦ�������������æµ��
    �������ŵĵط���һ���������(sign)��
LONG
        );
        set("exits", ([
                "south"   :  __DIR__"street9" ]) );

        set("objects", ([
              __DIR__"npc/weaponor" : 1, ]) );
        
        set("item_desc", ([
                "sign": (: look_sign :),]) );

        setup();

}

string look_sign(object me)
{
        return "����д������ʦ������רӪ��ʽ������\n";
}

