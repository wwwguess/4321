inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("��ɲ豭", ({ "tea cup","cup" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"����һ����ζŨ���ϵȺò衣���д����Ʒ���ġ�\n"
 "�������ţ��������Ŷ!\n");
                set("unit", "��");
                set("value", 20);
                set("max_liquid", 5);
        }
        set("liquid", ([
        	"name" : "������",
        	"remaining" : 5,
        	"type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

