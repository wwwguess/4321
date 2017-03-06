inherit NPC;
 
void give_jade();
void sell_drug();
 
void create()
{
        seteuid(getuid());
        set_name("������",({"shen wen-nien","shen"}));
        set("title","��������ƹ�");
        set("gender", "����" );
        set("age",45);
        set("combat_exp",30);
        set("attitude", "friendly" );
        set_temp("apply/dodge",5);
        set_temp("apply/attack",3);
        set("inquiry", ([
            "����" : (: give_jade :),
            "�ɺ�ҩ" : (: sell_drug :),
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver",1);
}
 
void init()
{
        add_action("list_item","list");
        add_action("buy_item","buy");
}
 
int list_item()
{
        write("�㿴��:\n");
        write("������һ��ڤֽ�������, ��� 10 ��Ǯ. ǽ�Ϲ���������ɨ��,\n");
        write("ÿ�� 50 ��Ǯ. ��̨�ϰ�\��һ��ľ��, ����д��:\n");
        write("�ײ�: ʱ��. û�����Ķ�����һ���ƹ��, ����Ӧ�ö���.\n");
        return 1;
}
 
int buy_item()
{
        command("shake");
        command("say �Ҳ���������İ����!");
        return 1;
}
 
void give_jade()
{
        object ob;
        if (this_player()->query_temp("give_alcohol")) {
               if(this_player()->query_temp("had_jade")) {
                    command("say ����̰��Ү... ");
                    return;
                }
                ob = new("/d/green/obj/jade1");
		if (ob->violate_unique()) {
		command("hmm");
		command("say ��������... �ո�������Ҫ����.");
		command("shrug");
		destruct(ob);
		return;
		}
                ob->move(this_object());
                command("give jade to "
                   +(string)this_player()->query("id"));
                this_player()->set_temp("had_jade",1);
           }
           else command("?");
        return;
}
 
void sell_drug()
{
        if (this_player()->query_temp("know_drug")) {
            command("whisper "+(string)this_player()->query("id")+
            " һ��ֻҪ 10 ������, ��֤��Ч�.\n");
            command("grin");
            this_player()->set_temp("can_buy_drug",1);
        }
        else command("?");
        return;
}
 
int accept_object(object who, object ob)
{
        object drug;
        if(who->query_temp("can_buy_drug") ) {
                if( ob->value() >= 1000 ) {
		drug = new("/obj/slumber_drug");
                drug->move(this_player());
                tell_room(environment(this_player()),
                "�ϰ������������һ��������"
                    +(string)this_player()->name()+"��\n",
                    ({this_object(), this_player()}) );
                tell_object(this_player(),"�ϰ�����һ���ɺ�ҩ���㡣\n");
                }
                else {
                command("shake");
                command("say ��ƭ�Ұ�?\n");
                this_player()->delete_temp("give_alcohol");
                this_player()->delete_temp("know_drug");
                }
        } else {
                command("say �Ҳ�֪�������Ǯ����, ����л��!");
                command("grin");
        }
        return 1;
}
 
