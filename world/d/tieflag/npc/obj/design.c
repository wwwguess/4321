
//  design.c
inherit ITEM;

void create()
{
        set_name("��ȸͼ", ({ "design"}) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��ȸ������ͼֽ\n");
                set("unit", "��");
                set("value", 0);
                set("material", "paper");
              }
        setup();
}
