// whip_book.c

inherit ITEM;

void create()
{
        set_name("��ѩ�޷�", ({ "whipbook" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"���ƺ���һ����ѩ�޷���ǰ��ҳ����Ȼ��û�й����ʽ����ϸ��˵������\n"
                        "ǰ���йر޷����ܸ��뾫�嵹�ǲ��١�\n");
                set("value", 260);
                set("material", "paper");
                set("skill", ([
                        "name":                 "snowwhip",        
                        "exp_required": 1000,
                        "sen_cost":             30,       
                        "difficulty":   20,   
                        "max_skill":    20    
                ]) );
        }
}

 
