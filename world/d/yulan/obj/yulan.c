#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("������", ({ "yulan" }) );
        set_weight(800000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ɵ���������������ż���С�֣�
��˵����λ���������ָ�������ħ�̵ı��������˰��㣬�Ӵ�����ɽ�֣������书��
��������һ��Ҫ���˳����������б�����������������ɽׯ�������潣��������
���ȣ�������˵ȥ�����ȣ�����㲻����ʶ��ͨ����ȥ�޻ء�\n");
                set("value", 3);
                //set("material", "gold");
        }
        init_hammer(65);
        setup();
}
