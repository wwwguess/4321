// Mon  08-21-95

#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("�˵�", ({ "kitchen knife", "knife" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","һ�ѾɾɵĲ˵�, ���ڼ�����ĥƽ��, �������ľ���ɱ����.\n");
        set("unit", "��");
		set("material", "iron");
	}
    init_blade(7);
	setup();
}

