// sword_book.c

inherit ITEM;

void create()
{
        set_name("˵�Ľ���", ({ "literatebook" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"����һ�����ܶ���ʶ�ֵ������鼮��\n"
                        "��ƪ�Ϻ�Ȼд����֮�����Ա���ʲô�ġ�\n");
                set("value", 2000);
                set("material", "paper");
                set("skill", ([
                        "name":                 "literate",        
                        "exp_required": 0,
                        "sen_cost":             30,       
                        "difficulty":   20,   
                        "max_skill":    30    
                ]) );
        }
}

 
