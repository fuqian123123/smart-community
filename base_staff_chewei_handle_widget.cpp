#include "base_staff_chewei_handle_widget.h"

BaseStaffCheWeiHandleWidget::BaseStaffCheWeiHandleWidget()
{}
int BaseStaffCheWeiHandleWidget::getStatus(const QString &key){
    QSqlQuery query;
    QString str=QString("select c_status from chewei"
                        " where pp_num=%1").arg(key);
    query.exec(str);
    query.next();
    return query.value(0).toInt();
}

bool BaseStaffCheWeiHandleWidget::isApplied(const QString &key,int type){
    //1 租赁 2购买
    QSqlQuery query;
    int ppNum=key.toInt();
    //判断有没有业主申请该车位
    QString str=QString("select count(*) from chewei_shenqing"
                        " where pp_num=%1"
                        " and c_s_type=%2"
                        " and c_s_del=0").arg(ppNum).arg(type);
    if(query.exec(str)){
       query.next();
       int count=query.value(0).toInt();
       if(count>0)
           return true;
    }
    return false;
}

bool BaseStaffCheWeiHandleWidget::handle(const QString &key,int type){
    QSqlQuery query;
    int ppNum=key.toInt();
    //根据车位号在车位申请表里查询最先申请该车位的业主
    QString str_1=QString("select account_num from chewei_shenqing"
                        " where c_s_date in"
                        " (select min(c_s_date) from chewei_shenqing)"
                        " and c_s_type=%1"
                        " and c_s_del=0").arg(type);
    if(!query.exec(str_1)){
        return false;
    }
    query.next();
    QString accountNum=query.value(0).toString();
    //type 1 已出租 2已出售
    QString str_2=QString("update chewei_shenqing set c_s_del=1"
                          " where pp_num=%1;"
                          "update chewei set account_num='%2',c_status=%3"
                          " where pp_num=%4 ")
                          .arg(ppNum).arg(accountNum).arg(type).arg(ppNum);
    if(!query.exec(str_2)){
        return false;
    }
    return true;
}
