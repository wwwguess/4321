inherit NPC;
void create()
{
        seteuid(getuid());
        set_name("С��",({"kid","child"}));
        set("gender", (:(random(50)>20)? "����" : "Ů��" :) );
        set("age",(random(3)+6));
        set("combat_exp",(random(10)+10));
        set("attitude", "friendly" );
        set_temp("apply/dodge",(random(2)+4));
        set("chat_chance",10);
        set("chat_msg",({
                "С���ܺ�������ŷ��￴ȥ��\n",
                "С��˵�����峤˵����ž��Բ����Դ��!\n",
                "С��˵������֪��������ʲô...\n",
                }) );
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin",(random(10)+10));
}
 
